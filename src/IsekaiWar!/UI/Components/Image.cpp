#include "Image.h"

#pragma region Local Dependencies

#include "../../Rendering/Spritesheet.h"

#pragma endregion

Image::Image(Spritesheet* spritesheet, Anchor anchor) {
	this->spritesheet = spritesheet;
	this->anchor = anchor;
}

void Image::UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor) {
	if (!enabled) return;
}

void Image::UpdateLogic(float deltaTime) {
	if (!enabled) return;
}

void Image::Enable() {
	enabled = true;
}

void Image::Disable() {
	enabled = false;
}

void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (!enabled) return;

	states.transform.combine(getTransform());
	target.draw(*spritesheet, states);
}