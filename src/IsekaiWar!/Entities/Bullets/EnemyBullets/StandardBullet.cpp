#include "StandardBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("laserBullet")
#define COLUMNS 1
#define ROWS 1
#define RADIUS 15.f
#define ATTACK 5.f
#define SPEED 400.f
#define SPEED_ANIMATION 2.f
#define SCALE 2.2f

StandardBullet::StandardBullet(float x, float y, sf::Vector2f direction)
	: EnemyBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, direction, SPEED)
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(90);
}

StandardBullet::StandardBullet(sf::Vector2f position, sf::Vector2f direction)
	: EnemyBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, direction, SPEED)
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(90);

}

void StandardBullet::UpdateLogic(float deltaTime) {
	EnemyBullet::UpdateLogic(deltaTime);

	for (CollidableEntity* entityHit : entitiesHit) {
		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit);

		if (!castEntity) {
			continue;
		}

		if (toDisable || toDestroy) {
			return;
		}

		Attack(castEntity);
		toDisable = true;
		return;
	}
}