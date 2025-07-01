#include "BackgroundEntity.h"
#include "../Managers.h"

BackgroundEntity::BackgroundEntity(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale)
	: Entity(position, texture, sf::Vector2i(1, 1)),
	TravellingModule(sf::Vector2f(0, 1), 20.f) {

	this->scale = scale;
	spritesheet.setOrigin(0, 0);
	spritesheet.setPosition(0, 0);
	texture->setRepeated(true);
	spritesheet.SetTexture(texture, 1, 1);
}

void BackgroundEntity::Traveling(float deltaTime) {
	u = u - normalisedDirection.x * deltaTime * speed;
	v = v - normalisedDirection.y * deltaTime * speed;

	spritesheet.SetTextureRect(sf::IntRect(int(u), int(v), scale.x, scale.y));
}

void BackgroundEntity::UpdateLogic(float deltaTime) {
	Traveling(deltaTime);
}

void BackgroundEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.combine(this->getTransform());
	target.draw(spritesheet, states);
}

void BackgroundEntity::Despawn() {
	Managers::GetInstance()->SceneManager->currentLevel->DespawnBackground(this);
}