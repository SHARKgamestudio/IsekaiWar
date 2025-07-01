#include "NeutralAuto.h"

#pragma region Local Dependencies

#include "../../../LivingEntity.h"
#include "../../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("neutralAuto")
#define COLUMNS 1
#define ROWS 2
#define RADIUS 20.f
#define ATTACK 0.7f
#define SPEED 500.f
#define SPEED_ANIMATION 2.f
#define SCALE 0.6f
#define POSITION_X -3
#define POSITION_Y 40

NeutralAuto::NeutralAuto(float x, float y, sf::Vector2f direction)
	: AutoBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, direction, SPEED, SPEED_ANIMATION) 
{
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.rotate(-90);
}

NeutralAuto::NeutralAuto(sf::Vector2f position, sf::Vector2f direction)
	: AutoBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, direction, SPEED, SPEED_ANIMATION)
{
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.rotate(-90);
}