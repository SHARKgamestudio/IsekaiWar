#include "VisualEffectEntity.h"

#include "../Managers.h"

VisualEffectEntity::VisualEffectEntity(float x, float y, sf::Texture* texture, int columns, int rows, float timeAnimation)
	: Entity(x, y, texture, columns, rows),
	animator(Animator(&spritesheet, { new Animation("forward", 0, columns * rows, 1.f, false) }))
{
	this->timeAnimation = timeAnimation;
	currentFrame = 0;
	nbFrames = columns * rows;

	animator.Play("forward");
}

VisualEffectEntity::VisualEffectEntity(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float timeAnimation)
	: Entity(position, texture, split),
	animator(Animator(&spritesheet, { new Animation("forward", 0, split.x * split.y, 1.f, false) }))
{
	this->timeAnimation = timeAnimation;
	currentFrame = 0;
	nbFrames = split.x * split.y;

	animator.Play("forward");
}

void VisualEffectEntity::UpdateLogic(float deltaTime) {
	Entity::UpdateLogic(deltaTime);

	animator.UpdateLogic(deltaTime);

	currentFrame += deltaTime;

	if (currentFrame + deltaTime * 2 >= timeAnimation) {
		Die();
	}
}

void VisualEffectEntity::Spawn() {
	Managers::GetInstance()->SceneManager->currentLevel->SpawnVisualEffect(this);
}