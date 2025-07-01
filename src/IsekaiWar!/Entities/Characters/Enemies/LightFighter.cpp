#include "LightFighter.h"

#include "../../../Managers.h"
#include "../../Bullets/EnemyBullets/StandardBullet.h"
#include "../../../Utils/Maths.h"
#include "../../../Utils/IntervalClock.h"
#include <iostream>

// behaviour
#define CIRCLE_RADIUS 256
#define START_DISTANCE 25

// constructor
#define INITIAL_POSITION_Y -256
#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("light-fighter")
#define COLUMNS 5
#define ROWS 4
#define RADIUS 64
#define HEALTH 2

LightFighter::LightFighter(float x, float y, float birth)
	: EnemyEntity(x, INITIAL_POSITION_Y, TEXTURE, birth, COLUMNS, ROWS, RADIUS, HEALTH), 
	shootClock(0.5f), 
	AttackModule(10) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = sf::Vector2f(x, y);
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");

	this->setScale(0.5f, 0.5f);
}

LightFighter::LightFighter(sf::Vector2f position, float birth)
	: EnemyEntity(sf::Vector2f(position.x, -256), Managers::GetInstance()->ResourceManager->GetTexture("enemy"), birth, sf::Vector2i(5, 4), 64, 2), 
	shootClock(0.5f), 
	AttackModule(10) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = position;
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

void LightFighter::UpdateLogic(float deltaTime) {
	EnemyEntity::UpdateLogic(deltaTime);

	if (!spawned) {
		AddToCheck(Managers::GetInstance()->SceneManager->currentLevel->GetPlayer());
		spawned = true;
	}

	CheckCollisions();

	animator->UpdateLogic(deltaTime);

	time += deltaTime * 48;

	setRotation(time - 90);

	// Convert the angle to radians
	float angleInRadians = time * (3.14159265f / 180.0f);

	// Compute the direction vector
	float cx = std::cos(angleInRadians);
	float cy = std::sin(angleInRadians);

	move(cx * deltaTime * 512, cy * deltaTime * 512);

	std::cout << entitiesHit.size();
	for (CollidableEntity* entityHit : entitiesHit) {
		LivingEntity* castEntity = dynamic_cast<LivingEntity*>(entityHit);

		if (!castEntity) {
			continue;
		}

		if (toDisable || toDestroy) {
			return;
		}

		Attack(castEntity, deltaTime);
		return;
	}

	if(GetHealth() <= 0) Die();
}