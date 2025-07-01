#include "EnemyBullet.h"

#pragma region Local Dependencies

#include "../../Managers.h"

#pragma endregion


EnemyBullet::EnemyBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed)
	: BulletEntity(x, y, texture, columns, rows, radius, attack, direction, speed) {
}

EnemyBullet::EnemyBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed)
	: BulletEntity(position, texture, split, radius, attack, direction, speed) {
}

void EnemyBullet::Spawn() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnEnnemyBullet(this);
}