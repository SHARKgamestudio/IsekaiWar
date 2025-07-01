#include "UltimeBullet.h"

#pragma region External Dependencies

#include <cmath>

#pragma endregion

#pragma region Local Dependencies

#include "../../LivingEntity.h"
#include "../../../Managers.h"

#pragma endregion

#define TEXTURE_FIRE Managers::GetInstance()->ResourceManager->GetTexture("fireUltime")
#define TEXTURE_LASER Managers::GetInstance()->ResourceManager->GetTexture("laserUltime")
#define PLAYER Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
#define COLUMNS 4
#define ROWS 2
#define RADIUS 30.f
#define ATTACK 10.f
#define SPEED 700.f
#define SPEED_ANIMATION 2.f
#define POSITION_X 0
#define POSITION_Y 60
#define DIRECTION_X  0
#define DIRECTION_Y -1

UltimeBullet::UltimeBullet(float x, float y)
	: PlayerBullet(x, y, TEXTURE_FIRE, COLUMNS, ROWS, RADIUS, ATTACK, sf::Vector2f(DIRECTION_X, DIRECTION_Y), SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS - 1, SPEED_ANIMATION) }),
	spriteLaser(Spritesheet(TEXTURE_LASER, 1, 1))
{
	entity = PLAYER;
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(1.5f, 1.5f);
	spritesheet.setRotation(180);
	distanceLaser = 140;

	animator.Play("forward");
}

UltimeBullet::UltimeBullet(sf::Vector2f position)
	: PlayerBullet(position, TEXTURE_FIRE, sf::Vector2i(COLUMNS, ROWS), RADIUS, ATTACK, sf::Vector2f(DIRECTION_X, DIRECTION_Y), SPEED),
	animator(&spritesheet, { new Animation("forward", 0, COLUMNS * ROWS - 1, SPEED_ANIMATION) }),
	spriteLaser(Spritesheet(TEXTURE_LASER, 1, 1))
{
	entity = Managers::GetInstance()->SceneManager->currentLevel->GetPlayer();
	spritesheet.setPosition(POSITION_X, POSITION_Y);
	spritesheet.setScale(1.5f, 1.5f);
	spritesheet.setRotation(180);
	distanceLaser = 140;

	animator.Play("forward");
}

void UltimeBullet::UpdateLogic(float deltaTime) {
	PlayerBullet::UpdateLogic(deltaTime);

	animator.UpdateLogic(deltaTime);

	if (!entitiesHit.empty()) {
		Attack(dynamic_cast<LivingEntity*>(entitiesHit[0]), deltaTime);
		spriteLaser.setScale(1, (entity->getPosition().y - entitiesHit[0]->getPosition().y - distanceLaser) / 90);
		spriteLaser.setPosition(0, (entity->getPosition().y - entitiesHit[0]->getPosition().y - distanceLaser) / 2);
		return;
	}

	spriteLaser.setScale(1, (entity->getPosition().y + 20 - distanceLaser) / 90);
	spriteLaser.setPosition(0, (entity->getPosition().y + 20 - distanceLaser) / 2);
}

void UltimeBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	CollidableEntity::draw(target, states);

	states.transform.combine(getTransform());
	target.draw(spriteLaser, states);
	target.draw(spritesheet, states);
}

void UltimeBullet::Move(float deltaTime) {
	if (!entitiesHit.empty()) {
		setPosition(sf::Vector2f(entity->getPosition().x, entitiesHit[0]->getPosition().y));
		return;
	}

	setPosition(sf::Vector2f(entity->getPosition().x, -9));
}

void UltimeBullet::UpdateLines() {
	for (int i = 0; i < lines.size(); i++) {
		lines[i][0].position = getPosition();
		lines[i][1].position = collisionsToCheck[i]->getPosition();
	}
}

void UltimeBullet::CheckCollisions() {
	entitiesHit.clear();

	for (CollidableEntity* otherEntity : collisionsToCheck) {

		float difference = getPosition().x - otherEntity->getPosition().x;

		if (std::abs(difference) >= radius + otherEntity->radius) continue;

		if (otherEntity->getPosition().y < -9.f) continue;

		if (entitiesHit.empty()) {
			entitiesHit.push_back(otherEntity);
			continue;
		}
		
		if (otherEntity->getPosition().y > entitiesHit[0]->getPosition().y) {
			Managers::GetInstance()->SoundManager->PlaySound("explosion");
			entitiesHit[0] = otherEntity;
			continue;
		}
	}
}