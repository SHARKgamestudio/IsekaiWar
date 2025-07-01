#include "FireAndWaterAuto.h"

#pragma region Local Dependencies

#include "../../../LivingEntity.h"
#include "../../../../Managers.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("fireAndWaterAuto")
#define COLUMNS 6
#define ROWS 1
#define RADIUS 30
#define ATTACK 1.2f
#define SPEED 700
#define SPEED_ANIMATION 2
#define SCALE 0.8f
#define POSITION_X 0
#define POSITION_Y 35


FireAndWaterAuto::FireAndWaterAuto(float x, float y, sf::Vector2f direction)
	: AutoBullet(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, direction, SPEED, SPEED_ANIMATION) 
{
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.rotate(90);
}

FireAndWaterAuto::FireAndWaterAuto(sf::Vector2f position, sf::Vector2f direction)
	: AutoBullet(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, direction, SPEED, SPEED_ANIMATION)
{
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.rotate(90);
}