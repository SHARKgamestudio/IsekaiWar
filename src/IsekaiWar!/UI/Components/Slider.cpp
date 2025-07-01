#include "Slider.h"

#include "../../Rendering/Spritesheet.h"

Slider::Slider(Spritesheet* handle, Spritesheet* background, Anchor anchor) {
	this->value = 0.0f;
	this->anchor = anchor;
	this->handle = handle;
	this->background = background;
}

void Slider::UpdateLogic(const sf::RenderWindow& window) {
	sf::FloatRect bounds = getTransform().transformRect(handle->sprite.getGlobalBounds());
	sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	bool inBounds = bounds.contains(mouse);
	bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	if (inBounds && isPressed) {
		handle->setPosition(mouse.x - bounds.width / 2, handle->getPosition().y);
	}
}

float Slider::GetValue() { return value; }

void Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());
	target.draw(*background, states);
	target.draw(*handle, states);
}