#pragma once

#pragma region Local Dependencies

#include "../UIComponent.h"

#pragma endregion

class Spritesheet;
class Text;

class Button : public UIComponent {
private:
	enum State {
		Normal,
		Hovered,
		Pressed,
		Disabled
	};

	bool changed;

	sf::Text* text;
	Spritesheet* spritesheet;

	float animatedValue;
	sf::Vector2f baseScale;

	State current;
	State previous;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	void Enable();
	void Disable();

	void UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor);
	void UpdateLogic(float deltaTime);

	void SetScale(float x, float y);

	void SetString(const std::string& str);

	Button(sf::Text* text, Spritesheet* spritesheet, Anchor anchor = Center);
	bool IsPressed();
};