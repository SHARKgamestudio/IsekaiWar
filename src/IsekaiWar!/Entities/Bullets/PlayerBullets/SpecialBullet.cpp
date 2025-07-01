#include "SpecialBullet.h"

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("specialBullet")
#define COLUMNS 1
#define ROWS 1
#define RADIUS 60.f
#define ATTACK 8.f
#define SPEED 400.f
#define SPEED_ROTATION 300
#define SCALE 0.15f
#define DIRECTION_X  0
#define DIRECTION_Y -1

SpecialBullet::SpecialBullet(float x, float y)
	: PlayerBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, sf::Vector2f(DIRECTION_X, DIRECTION_Y), SPEED)
{
	spritesheet.setScale(SCALE, SCALE);

}

SpecialBullet::SpecialBullet(sf::Vector2f position)
	: PlayerBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, sf::Vector2f(DIRECTION_X, DIRECTION_Y), SPEED)
{
	spritesheet.setScale(SCALE, SCALE);
}

void SpecialBullet::UpdateLogic(float deltaTime) {
	PlayerBullet::UpdateLogic(deltaTime);

	spritesheet.rotate(deltaTime * SPEED_ROTATION);


	for (CollidableEntity* entityHit : entitiesHit) {
		if (LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit)) {
			Managers::GetInstance()->SoundManager->PlaySound("explosion");
			Attack(castEntity, deltaTime);
		}
	}
}