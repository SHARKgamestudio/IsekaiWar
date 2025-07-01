#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"
#include "../../../Rendering/Animator.h"

#pragma endregion

class AutoBullet : public PlayerBullet {
	private:
		Animator animator;

	public:
		AutoBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed, float speedAnimation);
		AutoBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed, float speedAnimation);

		void UpdateLogic(float deltaTime) override;
};