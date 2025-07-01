#pragma once

#pragma region Local Dependencies

#include "../PowerUpEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class QuadrupleParchment : public PowerUpEntity {
	private:
		Animator animator;
	public:
		QuadrupleParchment(float x, float y);
		QuadrupleParchment(sf::Vector2f position);

		void Action();
};