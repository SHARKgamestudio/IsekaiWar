#pragma once

#pragma region Local Dependencies

#include "../PowerUpEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class DoubleParchment : public PowerUpEntity {
	private:
		Animator animator;
	public:
		DoubleParchment(float x, float y);
		DoubleParchment(sf::Vector2f position);

		void Action();
};