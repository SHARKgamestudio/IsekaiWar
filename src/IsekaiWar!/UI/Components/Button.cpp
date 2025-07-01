#include "Button.h"

#pragma region Local Dependencies

#include "../../Rendering/Spritesheet.h"
#include "../../Managers.h"

#pragma endregion

Button::Button(sf::Text* text, Spritesheet* spritesheet, Anchor anchor) {
	this->changed = false;
	this->text = text;
	this->enabled = true;
	this->current = State::Normal;
	this->previous = State::Normal;
	this->anchor = anchor;
	this->animatedValue = 0;
	this->spritesheet = spritesheet;

	// TEMP //
	text->setCharacterSize(64);
	text->setOrigin(text->getLocalBounds().width / 2.0f, text->getLocalBounds().height / 1.5f);
}

void Button::UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor) {
	if (!enabled) return;

	sf::FloatRect bounds = getTransform().transformRect(spritesheet->sprite.getGlobalBounds());

	bool inBounds = false;
	bool isPressed = false;
	if (Managers::GetInstance()->InputManager->isJoystickConnected()) {
		inBounds = bounds.intersects(cursor);
		isPressed = Managers::GetInstance()->InputManager->GetKeyDown("Confirm");
	}
	else {
		inBounds = bounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
		isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}

	current = inBounds ? (isPressed ? State::Pressed : State::Hovered) : State::Normal;

	if (current != previous) { changed = true; previous = current; } else { changed = false; }

	if (changed) {
		if (current == State::Hovered && previous != State::Pressed) {
			Managers::GetInstance()->SoundManager->PlaySound("select");
		}
		if (current == State::Pressed) {
			Managers::GetInstance()->SoundManager->PlaySound("confirm");
		}
	}

	spritesheet->current = current;
	spritesheet->UpdateViewport();
}

void Button::UpdateLogic(float deltaTime) {
	if (!enabled) return;

	if (current == 1 && animatedValue < 1) { animatedValue += deltaTime * 4; }
	else if (animatedValue > 0.0f) { animatedValue -= deltaTime * 4; }

	float scale = std::pow(animatedValue, 2) / 32;
	setScale(baseScale.x + scale, baseScale.y + scale);
}

void Button::SetScale(float x, float y) {
	baseScale = sf::Vector2f(x, y);
	setScale(x, y);
}

void Button::SetString(const std::string& str)
{
	if (text) {
		text->setString(str);
		//text->setOrigin(text->getLocalBounds().width / 2.0f, text->getLocalBounds().height / 1.5f);
	}
}

void Button::Enable() {
	enabled = true;
	current = State::Normal;
}

void Button::Disable() {
	enabled = false;
	current = State::Normal;
}

bool Button::IsPressed() {
	return current == State::Pressed;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (!enabled) return;

	states.transform.combine(getTransform());
	target.draw(*spritesheet, states);
	target.draw(*text, states);
}