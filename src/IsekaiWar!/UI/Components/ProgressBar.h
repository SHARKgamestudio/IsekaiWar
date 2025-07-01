#pragma once

#pragma region Local Dependencies

#include "../UIComponent.h"

#pragma endregion

class Spritesheet;

class ProgressBar : public UIComponent {
private:
	float value;
	float size;

	sf::Text* text;

	Spritesheet* leftFill; Spritesheet* leftBackground; float leftFactor;
	Spritesheet* middleFill; Spritesheet* middleBackground; float middleFactor;
	Spritesheet* rightFill; Spritesheet* rightBackground; float rightFactor;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	void SetFactors(float leftFill, float middleFill, float rightFill);

	void SetText(std::string text);
	void SetValue(float percent);

	void Enable();
	void Disable();

	void UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor);
	void UpdateLogic(float deltaTime);

	ProgressBar(Spritesheet* leftFill, Spritesheet* middleFill, Spritesheet* rightFill, Spritesheet* leftBackground, Spritesheet* middleBackground, Spritesheet* rightBackground, float size, Anchor anchor = Center);
};