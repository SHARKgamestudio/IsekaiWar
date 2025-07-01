#pragma once

#pragma region Local Dependencies

#include "../PowerUpEntity.h"
#include "../../Rendering/Animator.h"

#pragma endregion

class FireBook : public PowerUpEntity {
	private:
		Animator animator;
	public:
		FireBook(float x, float y);
		FireBook(sf::Vector2f position);

		void Action();
};