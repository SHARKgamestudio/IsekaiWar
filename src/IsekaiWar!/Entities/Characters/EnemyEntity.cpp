#include "EnemyEntity.h"

#include "../VisualEffectEntity.h"
#include "../../Managers.h"
#include "../../Entities/PowerUps/FireBook.h"
#include "../../Entities/PowerUps/WaterBook.h"
#include "../../Entities/PowerUps/DoubleParchment.h"
#include "../../Entities/PowerUps/TripleParchment.h"
#include "../../Entities/PowerUps/QuadrupleParchment.h"

EnemyEntity::EnemyEntity(float x, float y, sf::Texture* texture, float birth, int columns, int rows, float radius, float health, bool right)
	: CharacterEntity(x, y, texture, columns, rows, radius, health),
	LootModule() {
	this->birth = birth;
	this->right = right;
}

EnemyEntity::EnemyEntity(sf::Vector2f position, sf::Texture* texture, float birth, sf::Vector2i split, float radius, float health, bool right)
	: CharacterEntity(position, texture, split, radius, health),
	LootModule() {
	this->birth = birth;
	this->right = right;
}

void EnemyEntity::UpdateLogic(float deltaTime) {
	LivingEntity::UpdateLogic(deltaTime);

	if (toDestroy) {
		(new VisualEffectEntity(getPosition(), Managers::GetInstance()->ResourceManager->GetTexture("explosion"), sf::Vector2i(6, 1), 0.8f))->Spawn();

		Loot(getPosition());
		
		Managers::GetInstance()->SceneManager->currentLevel->UpdateScore(200);
		Managers::GetInstance()->SceneManager->currentLevel->GetPlayer()->ObtainMana(10);
	}
}