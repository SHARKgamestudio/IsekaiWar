#pragma once

#pragma region Local Dependencies

#include "../BulletEntity.h"

#pragma endregion

class EnemyBullet : public BulletEntity {
public:
	EnemyBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed);
	EnemyBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed);

	void Spawn();
};