#include "FireBook.h"

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Entities/Characters/PlayerEntity.h"

#pragma endregion

#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("fireBook")
#define COLUMNS 1
#define ROWS 1
#define RADIUS 30.f
#define ATTACK 2.f
#define DIRECTION_X  0.f
#define DIRECTION_Y  1.f
#define SPEED 200.f
#define SPEED_ANIMATION 2.f
#define SCALE 0.1f

FireBook::FireBook(float x, float y)
	: PowerUpEntity(x, y, TEXTURE, COLUMNS, ROWS, RADIUS, ATTACK, sf::Vector2f(DIRECTION_X, DIRECTION_Y), SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS, SPEED_ANIMATION) })
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

FireBook::FireBook(sf::Vector2f position)
	: PowerUpEntity(position, TEXTURE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, sf::Vector2f(DIRECTION_X, DIRECTION_Y), SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS, SPEED_ANIMATION) })
{
	spritesheet.setScale(SCALE, SCALE);
	spritesheet.setRotation(-90);

	animator.Play("forward");
}

void FireBook::Action() {
	PlayerEntity* player = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	player->isFire = true;
	player->UpdateBullets();
}