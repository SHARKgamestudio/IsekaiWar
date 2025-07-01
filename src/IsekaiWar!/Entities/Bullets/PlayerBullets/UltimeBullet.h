#pragma once

#pragma region Local Dependencies

#include "../PlayerBullet.h"
#include "../../../Modules/MoveModule.h"
#include "../../../Rendering/Animator.h"

#pragma endregion

class UltimeBullet : public PlayerBullet {
protected:
	Animator animator;
	Spritesheet spriteLaser;
	int distanceLaser;

public:
	UltimeBullet(float x, float y);
	UltimeBullet(sf::Vector2f position);

	void Move(float deltaTime);
	void UpdateLogic(float deltaTime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void UpdateLines();
	void CheckCollisions();
};