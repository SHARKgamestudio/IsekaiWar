#pragma once

#pragma region Local Dependencies

#include "../EnemyBullet.h"
#include "../../../Modules/MoveModule.h"

#pragma endregion

class StandardBullet : public EnemyBullet {
public:
	StandardBullet(float x, float y, sf::Vector2f direction);
	StandardBullet(sf::Vector2f position, sf::Vector2f direction);

	void UpdateLogic(float deltaTime);
};