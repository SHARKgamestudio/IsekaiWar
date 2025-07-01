#pragma once

#pragma region Local Dependencies

#include "../AutoBullet.h"
#include "../../../../Rendering/Animator.h"

#pragma endregion

class FireAndWaterAuto : public AutoBullet {
	public:
		FireAndWaterAuto(float x, float y, sf::Vector2f direction);
		FireAndWaterAuto(sf::Vector2f position, sf::Vector2f direction);
};