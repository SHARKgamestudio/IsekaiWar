#pragma once

#include "../UIComponent.h"

class Spritesheet;

class Slider : public UIComponent {
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	float value;
	Spritesheet* handle;
	Spritesheet* background;
public:
	Slider(Spritesheet* handle, Spritesheet* background, Anchor anchor = Center);
	void UpdateLogic(const sf::RenderWindow& window);
	float GetValue();
};