#include "LevelScene.h"

#pragma region External Dependencies

#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../Utils/Clock.h"

#pragma endregion

LevelScene::~LevelScene() {
	delete player;

	for (auto background : backgrounds)
		delete background;
	backgrounds.clear();

	for (auto enemy : ennemies)
		delete enemy;
	ennemies.clear();

	for (auto entity : entities)
		delete entity;
	entities.clear();

	for (auto bullet : bullets)
		delete bullet;
	bullets.clear();

	for (auto effect : visualEffects)
		delete effect;
	visualEffects.clear();

	delete comboClock;
}

void LevelScene::UpdateLogic(float deltaTime) {
	player->UpdateLogic(deltaTime);

	for (BackgroundEntity* background : backgrounds) {
		background->UpdateLogic(deltaTime);
	}

	for (CollidableEntity* entity : entities) {
		entity->UpdateLogic(deltaTime);

		if (entity->ToDestroy()) {
			entitiesToDestroy.push_back(entity);
		}
	}

	for (EnemyEntity* ennemy : ennemies) {
		ennemy->UpdateLogic(deltaTime);

		if (ennemy->ToDestroy()) {
			ennemiesToDestroy.push_back(ennemy);
		}
	}

	for (BulletEntity* bullet : bullets) {
		bullet->UpdateLogic(deltaTime);

		if (bullet->ToDestroy()) {
			bulletsToDestroy.push_back(bullet);
		}
	}

	for (VisualEffectEntity* visualEffect : visualEffects) {
		visualEffect->UpdateLogic(deltaTime);

		if (visualEffect->ToDestroy()) {
			visualEffectsToDestroy.push_back(visualEffect);
		}
	}

	// PARCOURS DE DESPAWN
	for (CollidableEntity* entity : entitiesToDestroy) {
		DespawnEntity(entity);
	}

	for (EnemyEntity* ennemy : ennemiesToDestroy) {
		DespawnEnnemy(ennemy);
	}

	for (BulletEntity* bullet : bulletsToDestroy) {
		DespawnBullet(bullet);
	}

	for (VisualEffectEntity* visualEffect : visualEffectsToDestroy) {
		DespawnVisualEffect(visualEffect);
	}

	entitiesToDestroy.clear();
	ennemiesToDestroy.clear();
	bulletsToDestroy.clear();

	// Reset combo
	comboIsBreak = comboClock->UpdateLogic(deltaTime);

	if (comboIsBreak) {
		multiplicator = 1;
	}
}

void LevelScene::Draw(sf::RenderWindow& window) {
	for (BackgroundEntity* background : backgrounds) {
		window.draw(*background);
	}

	for (CollidableEntity* entity : entities) {
		window.draw(*entity);
	}

	for (EnemyEntity* ennemy : ennemies) {
		window.draw(*ennemy);
	}

	for (BulletEntity* bullet : bullets) {
		window.draw(*bullet);
	}

	for (VisualEffectEntity* visualEffect : visualEffects) {
		window.draw(*visualEffect);
	}

	window.draw(*player);
}

std::vector<CollidableEntity*>* LevelScene::GetEntities() {
	return &entities;
}

PlayerEntity* LevelScene::GetPlayer() {
	return player;
}

void LevelScene::Load() {
	backgrounds.clear();
	ennemies.clear();
	entities.clear();
	bullets.clear();
	visualEffects.clear();

	comboClock = new IntervalClock(3);
}

void LevelScene::SpawnPlayerBullet(BulletEntity* bullet) {
	for (EnemyEntity* ennemy : ennemies) {
		bullet->AddToCheck(ennemy);
	}
	bullets.push_back(bullet);
}

void LevelScene::SpawnEnnemyBullet(BulletEntity* bullet) {
	bullet->AddToCheck(player);

	bullets.push_back(bullet);
}

void LevelScene::DespawnBullet(BulletEntity* bullet) {
	std::_Vector_iterator it = std::find(bullets.begin(), bullets.end(), bullet);

	if (it != bullets.end()) {
		int index = std::distance(bullets.begin(), it);

		bullets.erase(it);
	}
}

void LevelScene::SpawnVisualEffect(VisualEffectEntity* visualEffect) {
	visualEffects.push_back(visualEffect);
}

void LevelScene::DespawnVisualEffect(VisualEffectEntity* visualEffect) {
	std::_Vector_iterator it = std::find(visualEffects.begin(), visualEffects.end(), visualEffect);

	if (it != visualEffects.end()) {
		int index = std::distance(visualEffects.begin(), it);

		visualEffects.erase(it);
	}
}

void LevelScene::SpawnEnnemy(EnemyEntity* ennemy) {
	for (BulletEntity* bullet : bullets) {
		bullet->AddToCheck(ennemy);
	}

	ennemies.push_back(ennemy);
}

void LevelScene::DespawnEnnemy(EnemyEntity* ennemy) {
	std::_Vector_iterator it = std::find(ennemies.begin(), ennemies.end(), ennemy);

	if (it != ennemies.end()) {
		int index = std::distance(ennemies.begin(), it);

		ennemies.erase(it);
	}

	for (BulletEntity* bullet : bullets) {
		bullet->RemoveToCheck(ennemy);
	}
}

void LevelScene::SpawnEntity(CollidableEntity* entity) {
	entity->AddToCheck(player);

	entities.push_back(entity);
}

void LevelScene::DespawnEntity(CollidableEntity* entity) {
	std::_Vector_iterator it = std::find(entities.begin(), entities.end(), entity);

	if (it != entities.end()) {
		int index = std::distance(entities.begin(), it);

		entities.erase(it);
	}

	for (BulletEntity* bullet : bullets) {
		bullet->RemoveToCheck(entity);
	}
}

void LevelScene::SpawnBackground(BackgroundEntity* background) {
	backgrounds.push_back(background);
}

void LevelScene::DespawnBackground(BackgroundEntity* background) {
	std::_Vector_iterator it = std::find(backgrounds.begin(), backgrounds.end(), background);

	if (it != backgrounds.end()) {
		int index = std::distance(backgrounds.begin(), it);

		backgrounds.erase(it);
	}
}

void LevelScene::UpdateScore(int score) {
	this->score += score * multiplicator;

	multiplicator += 0.1f;
	comboClock->Restart();
}