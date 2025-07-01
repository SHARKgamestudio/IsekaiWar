#include "PlayerBullet.h"

#pragma region Local Dependencies

#include "../../Managers.h"

#pragma endregion

PlayerBullet::PlayerBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed)
	: BulletEntity(x, y, texture, columns, rows, radius, attack, direction, speed) {
}

PlayerBullet::PlayerBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed)
	: BulletEntity(position, texture, split, radius, attack, direction, speed) {
}

void PlayerBullet::Spawn() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnPlayerBullet(this);
}