#pragma once

#pragma region Local Dependencies

#include "../UIComponent.h"

#pragma endregion


class Label : public UIComponent {
private:
	sf::Text* text;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	void Enable();
	void Disable();

	void UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor);
	void UpdateLogic(float deltaTime);

	void SetCharSize(float size);
	void SetText(std::string text);

	Label(std::string text, Anchor anchor = Center);
};