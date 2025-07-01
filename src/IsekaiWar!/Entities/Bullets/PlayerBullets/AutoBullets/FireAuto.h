#pragma once

#pragma region Local Dependencies

#include "../AutoBullet.h"
#include "../../../../Rendering/Animator.h"

#pragma endregion

class FireAuto : public AutoBullet {
	public:
		FireAuto(float x, float y, sf::Vector2f direction);
		FireAuto(sf::Vector2f position, sf::Vector2f direction);
};