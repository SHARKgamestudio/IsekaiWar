#include "Label.h"

#include "../../Managers.h"

Label::Label(std::string text, Anchor anchor) {
	this->text = new sf::Text();
	this->text->setString(text);
	this->text->setCharacterSize(65);
	this->text->setFillColor(sf::Color::White);
	this->text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	this->anchor = anchor;
}

void Label::UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor) {
	if (!enabled) return;
}

void Label::UpdateLogic(float deltaTime) {
	if (!enabled) return;
}

void Label::SetCharSize(float size) {
	this->text->setCharacterSize(size);
}

void Label::SetText(std::string text) {
	this->text->setString(text);
}

void Label::Enable() {
	enabled = true;
}

void Label::Disable() {
	enabled = false;
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (!enabled) return;

	states.transform.combine(getTransform());
	target.draw(*text, states);
}