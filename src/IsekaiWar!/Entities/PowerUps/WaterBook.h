#pragma once

#pragma region Local Dependencies

#include "../PowerUpEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class WaterBook : public PowerUpEntity {
	private:
		Animator animator;
	public:
		WaterBook(float x, float y);
		WaterBook(sf::Vector2f position);

		void Action();
};