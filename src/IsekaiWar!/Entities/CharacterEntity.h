#pragma once

#pragma region Local Dependencies

#include "LivingEntity.h"
#include "../Modules/MoveModule.h"

#pragma endregion

class CharacterEntity : public LivingEntity, public MoveModule {
public:
	CharacterEntity(float x, float y, sf::Texture* texture, int columns = 1, int rows = 1, float radius = 8, float health = 1);
	CharacterEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split = sf::Vector2i(1, 1), float radius = 8, float health = 1);
	
	void Move(float deltaTime);
	void Despawn();
};