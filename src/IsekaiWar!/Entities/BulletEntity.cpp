#include "BulletEntity.h"
#include "../Managers.h"
#include <cmath>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

BulletEntity::BulletEntity(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed)
	: CollidableEntity(x, y, texture, columns, rows, radius),
	AttackModule(attack),
	MoveModule(direction, speed) 
{
	spritesheet.setRotation( -atan2(direction.x, direction.y) * 180.0 / 3.14f);
}

BulletEntity::BulletEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed)
	: CollidableEntity(position, texture, split, radius),
	AttackModule(attack),
	MoveModule(direction, speed) 
{
	spritesheet.setRotation( -atan2(direction.x, direction.y) * 180.0 / 3.14f);
}

void BulletEntity::Move(float deltaTime) {
	this->move(normalisedDirection * deltaTime * speed);
}

void BulletEntity::UpdateLogic(float deltaTime) {
	CollidableEntity::UpdateLogic(deltaTime);

	Move(deltaTime);

	CheckCollisions();

	sf::Vector2f pos = getPosition();
	if (-20 > pos.x || pos.x > WINDOW_WIDTH / 2 + 20 || -20 > pos.y || pos.y > WINDOW_HEIGHT + 20) {
		Die();
	}
}