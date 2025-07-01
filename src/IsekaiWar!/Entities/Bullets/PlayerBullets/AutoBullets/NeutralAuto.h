#pragma once

#pragma region Local Dependencies

#include "../AutoBullet.h"
#include "../../../../Rendering/Animator.h"

#pragma endregion

class NeutralAuto : public AutoBullet {
	public:
		NeutralAuto(float x, float y, sf::Vector2f direction);
		NeutralAuto(sf::Vector2f position, sf::Vector2f direction);
};