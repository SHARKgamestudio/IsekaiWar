#include "CharacterEntity.h"

#pragma region Local Dependencies

#include "../Managers.h"

#pragma endregion

CharacterEntity::CharacterEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float health)
	: LivingEntity(x, y, texture, columns, rows, radius, health),
	MoveModule(sf::Vector2f(0, 0), 0) {
}

CharacterEntity::CharacterEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float health)
	: LivingEntity(position, texture, split, radius, health),
	MoveModule(sf::Vector2f(0, 0), 0) {
}

void CharacterEntity::Move(float deltaTime) {
	// Move the entity //
}

void CharacterEntity::Despawn() {
	Managers::GetInstance()->SceneManager->currentLevel->DespawnEntity(this);
}