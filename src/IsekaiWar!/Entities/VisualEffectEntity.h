#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../Entity.h"
#include "../Modules/MoveModule.h"
#include "../Rendering/Animator.h"

#pragma endregion

class VisualEffectEntity : public Entity {
private:
	Animator animator;
	float timeAnimation;
	int nbFrames;
	float currentFrame;

public:
	VisualEffectEntity(float x, float y, sf::Texture* texture, int columns, int rows, float timeAnimation);
	VisualEffectEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float timeAnimation);

	void UpdateLogic(float deltaTime) override;
	void Spawn();
};