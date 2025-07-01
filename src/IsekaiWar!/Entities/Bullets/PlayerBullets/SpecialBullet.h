#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"
#include "../../../Rendering/Animator.h"

#pragma endregion

class SpecialBullet : public PlayerBullet {
	public:
		SpecialBullet(float x, float y);
		SpecialBullet(sf::Vector2f position);

		void UpdateLogic(float deltaTime) override;
};