#include "LivingEntity.h"
#include "../Managers.h"

LivingEntity::LivingEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float health)
	: CollidableEntity(x, y, texture, columns, rows, radius),
	HealthModule(health) {
}

LivingEntity::LivingEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float health)
	: CollidableEntity(position, texture, split, radius),
	HealthModule(health) {
}

void LivingEntity::UpdateLogic(float deltaTime) {
	CollidableEntity::UpdateLogic(deltaTime);

	if (hasTakeDamage) {
		spritesheet.sprite.setColor(sf::Color(255, 0, 0));
		hasTakeDamage = !hitClock.UpdateLogic(deltaTime);
	}
	else {
		spritesheet.sprite.setColor(sf::Color(255, 255, 255));
	}
}