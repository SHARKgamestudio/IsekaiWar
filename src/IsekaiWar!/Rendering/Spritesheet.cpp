#include "Spritesheet.h"

#pragma region External Dependencies

#include <string>

#pragma endregion

Spritesheet::Spritesheet() {
	this->current = 0;
	this->hres = 0; this->vres = 0;
	this->columns = 1; this->rows = 1;

	this->sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	this->sprite.setOrigin(hres / 2, vres / 2);
}

Spritesheet::Spritesheet(sf::Texture* texture, int columns, int rows) {
	this->current = 0;
	this->SetTexture(texture, columns, rows);
	this->sprite.setOrigin(hres / 2, vres / 2);
}

void Spritesheet::SetTexture(sf::Texture* texture, int columns, int rows) {
	this->columns = columns; this->rows = rows;

	this->sprite.setTexture(*texture);

	this->hres = texture->getSize().x / this->columns;
	this->vres = texture->getSize().y / this->rows;

	this->sprite.setTextureRect(sf::IntRect(0, 0, this->hres, this->vres));
}

void Spritesheet::SetTextureRect(sf::IntRect rect) {
	this->sprite.setTextureRect(rect);
}

void Spritesheet::UpdateViewport() {
	int x = current % columns;
	int y = current / columns;

	this->sprite.setTextureRect(sf::IntRect(x * hres, y * vres, hres, vres));
}

void Spritesheet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(this->getTransform());
	target.draw(this->sprite, states);
}