#pragma once

#pragma region Local Dependencies

#include "../UIComponent.h"

#pragma endregion

class Spritesheet;

class Image : public UIComponent {
private:
	Spritesheet* spritesheet;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
public:
	void Enable();
	void Disable();

	void UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor);
	void UpdateLogic(float deltaTime);

	Image(Spritesheet* spritesheet, Anchor anchor = Center);
};