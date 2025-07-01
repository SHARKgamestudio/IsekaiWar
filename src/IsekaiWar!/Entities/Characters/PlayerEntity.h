#pragma once

#pragma region Local Dependencies

#include "../CharacterEntity.h"
#include "../../Rendering/Animator.h"
#include "../../Modules/ShootModule.h"
#include "../../Modules/ManaModule.h"

#pragma endregion

class InputManager;
class UltimeBullet;
class ProgressBar;
class Label;

class PlayerEntity : public CharacterEntity, public ShootModule, public ManaModule {
private:
	ProgressBar* healthbar;
	ProgressBar* manabar;

	ProgressBar* autobar;
	ProgressBar* specialbar;
	ProgressBar* burstbar;

	Label* scoretext;
	Label* multiplicatortext;

	Animator* animator;
	float angle;
	InputManager* inputs;

public:
	PlayerEntity();

	void UpdateLogic(float deltaTime);
	void TakeDamage(float damage) override;
};