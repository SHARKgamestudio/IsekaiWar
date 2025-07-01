#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"
#include "../../Rendering/Animator.h"
#include "../../Modules/LootModule.h"

#pragma endregion

class EnemyEntity : public CharacterEntity, public LootModule {
public:
	float birth = 0;
	bool right;

	EnemyEntity(float x, float y, sf::Texture* texture, float birth = 0, int columns = 1, int rows = 1, float radius = 8, float health = 1, bool right = true);
	EnemyEntity(sf::Vector2f position, sf::Texture* texture, float birth = 0, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1, bool right = true);

	void UpdateLogic(float deltaTime) override;
};