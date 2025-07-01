#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"
#include "../Entities/CollidableEntity.h"
#include "../Entities/BackgroundEntity.h"
#include "../Entities/VisualEffectEntity.h"
#include "../Entities/BulletEntity.h"
#include "../Entities/Characters/PlayerEntity.h"
#include "../Entities/Characters/EnemyEntity.h"
#include "../Utils/IntervalClock.h"

#pragma endregion

class LevelScene : public Scene {
protected:
	PlayerEntity* player;
	std::vector<BackgroundEntity*> backgrounds;
	std::vector<EnemyEntity*> ennemies;
	std::vector<CollidableEntity*> entities;
	std::vector<BulletEntity*> bullets;
	std::vector<VisualEffectEntity*> visualEffects;

	std::vector<CollidableEntity*> entitiesToDestroy;
	std::vector<EnemyEntity*> ennemiesToDestroy;
	std::vector<BulletEntity*> bulletsToDestroy;
	std::vector<VisualEffectEntity*> visualEffectsToDestroy;

	IntervalClock* comboClock;
	bool comboIsBreak;

public:
	float multiplicator;
	int score;

	~LevelScene();

	std::vector<CollidableEntity*>* GetEntities();
	PlayerEntity* GetPlayer();

	void virtual Load();

	void virtual UpdateLogic(float dt);
	void virtual Draw(sf::RenderWindow& window) override;

	void virtual SpawnPlayerBullet(BulletEntity* bullet);
	void virtual SpawnEnnemyBullet(BulletEntity* bullet);
	void virtual DespawnBullet(BulletEntity* bullet);

	void virtual SpawnVisualEffect(VisualEffectEntity* visualEffect);

	void virtual DespawnVisualEffect(VisualEffectEntity* visualEffect);
	void virtual SpawnEnnemy(EnemyEntity* ennemy);
	void virtual DespawnEnnemy(EnemyEntity* ennemy);

	void virtual SpawnEntity(CollidableEntity* entity);
	void virtual DespawnEntity(CollidableEntity* entity);

	void virtual SpawnBackground(BackgroundEntity* background);
	void virtual DespawnBackground(BackgroundEntity* background);

	void UpdateScore(int score);
};