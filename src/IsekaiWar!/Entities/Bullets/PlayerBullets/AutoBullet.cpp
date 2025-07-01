#include "AutoBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

AutoBullet::AutoBullet(float x, float y, sf::Texture* texture, int columns, int rows, float radius, float attack, sf::Vector2f direction, float speed, float speedAnimation)
	: PlayerBullet(x, y, texture, columns, rows, radius, attack, direction, speed),
	animator(&spritesheet, { new Animation("forward", 0, (columns * rows) - 1, speedAnimation) }) {
	animator.Play("forward");
}

AutoBullet::AutoBullet(sf::Vector2f position, sf::Texture* texture, sf::Vector2i split, float radius, float attack, sf::Vector2f direction, float speed, float speedAnimation)
	: PlayerBullet(position, texture, split, radius, attack, direction, speed),
	animator(&spritesheet, { new Animation("forward", 0, (split.x * split.y) - 1, speedAnimation) }) {
	animator.Play("forward");
}

void AutoBullet::UpdateLogic(float deltaTime) {
	PlayerBullet::UpdateLogic(deltaTime);

	animator.UpdateLogic(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {

		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit);

		if (!castEntity) {
			continue;
		}

		if (toDisable || toDestroy) {
			return;
		}

		Managers::GetInstance()->SoundManager->PlaySound("explosion");
		Attack(castEntity);
		toDisable = true;
		return;
	}
}