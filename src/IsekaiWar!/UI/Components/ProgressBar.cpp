#include "ProgressBar.h"

#include "../../Rendering/Spritesheet.h"
#include "../../Managers.h"

ProgressBar::ProgressBar(Spritesheet* leftFill, Spritesheet* middleFill, Spritesheet* rightFill, Spritesheet* leftBackground, Spritesheet* middleBackground, Spritesheet* rightBackground, float size, Anchor anchor) {
	this->value = 0;
	
	this->size = size;

	this->leftFill = leftFill;
	this->middleFill = middleFill;
	this->rightFill = rightFill;

	this->leftBackground = leftBackground;
	this->middleBackground = middleBackground;
	this->rightBackground = rightBackground;

	this->anchor = anchor;

	this->leftFactor = 0;
	this->middleFactor = 0;
	this->rightFactor = 0;

	leftFill->setOrigin(0, 0);
	middleFill->setOrigin(0, 0);
	rightFill->setOrigin(0, 0);

	this->text = new sf::Text();
	this->text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	this->text->setCharacterSize(12);
	this->text->setFillColor(sf::Color::Black);
	this->text->setString("24");
	this->text->setOrigin(0, 0);
	this->text->setPosition(leftFactor + 12, -this->leftFill->sprite.getGlobalBounds().height / 3);
}

void ProgressBar::SetFactors(float leftFill, float middleFill, float rightFill) {
	leftFactor = leftFill;
	middleFactor = middleFill;
	rightFactor = rightFill;
}

void ProgressBar::SetText(std::string text) {
	this->text->setString(text);
}

void ProgressBar::SetValue(float percent) {
	this->value = percent;
}

void ProgressBar::Enable() {
}

void ProgressBar::Disable() {
}

void ProgressBar::UpdateCursor(const sf::RenderWindow& window, sf::FloatRect cursor) {
	float expand = (value / 100) * size;
	leftFill->setPosition(leftFactor, 0);
	middleFill->setScale(expand + 1, 1);
	middleFill->setPosition(leftFill->sprite.getGlobalBounds().width - middleFactor, 0);
	rightFill->setPosition(leftFill->sprite.getGlobalBounds().width + middleFill->sprite.getGlobalBounds().width - rightFactor + expand, 0);

	leftBackground->setPosition(leftFactor, 0);
	middleBackground->setScale(size + 1, 1);
	middleBackground->setPosition(leftFill->sprite.getGlobalBounds().width - middleFactor, 0);
	rightBackground->setPosition(leftFill->sprite.getGlobalBounds().width + middleFill->sprite.getGlobalBounds().width - rightFactor + size, 0);
}

void ProgressBar::UpdateLogic(float deltaTime) {
}

void ProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(getTransform());

	target.draw(*leftBackground, states);
	target.draw(*middleBackground, states);
	target.draw(*rightBackground, states);

	target.draw(*leftFill, states);
	target.draw(*middleFill, states);
	target.draw(*rightFill, states);

	target.draw(*text, states);
}