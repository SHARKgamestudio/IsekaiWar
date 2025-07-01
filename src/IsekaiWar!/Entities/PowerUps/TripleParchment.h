#pragma once

#pragma region Local Dependencies

#include "../PowerUpEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class TripleParchment : public PowerUpEntity {
	private:
		Animator animator;
	public:
		TripleParchment(float x, float y);
		TripleParchment(sf::Vector2f position);

		void Action();
};