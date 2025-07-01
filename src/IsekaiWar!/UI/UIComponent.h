#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

enum Anchor {
	TopLeft,
	TopCenter,
	TopRight,
	CenterLeft,
	Center,
	CenterRight,
	BottomLeft,
	BottomCenter,
	BottomRight
};

class UIComponent : public sf::Drawable, public sf::Transformable {
public:
	bool enabled = true;
	Anchor anchor = Center;

	virtual void Enable() = 0;
	virtual void Disable() = 0;
	virtual void UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor) = 0;
	virtual void UpdateLogic(float deltaTime) = 0;
};