#include "HeavyFighter.h"

#include "../../../Managers.h"
#include "../../Bullets/EnemyBullets/StandardBullet.h"
#include "../../../Utils/Maths.h"
#include "../../../Utils/IntervalClock.h"

// behaviour
#define CIRCLE_RADIUS 64
#define START_DISTANCE 25

// constructor
#define INITIAL_POSITION_Y -256
#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("heavy-fighter")
#define COLUMNS 5
#define ROWS 4
#define RADIUS 64
#define HEALTH 7
#define RELOAD 0.7f

HeavyFighter::HeavyFighter(float x, float y, float birth)
	: EnemyEntity(x, INITIAL_POSITION_Y, TEXTURE, birth, COLUMNS, ROWS, RADIUS, HEALTH), 
	shootClock(0.7f) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = sf::Vector2f(x, y);
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

HeavyFighter::HeavyFighter(sf::Vector2f position, float birth)
	: EnemyEntity(sf::Vector2f(position.x, INITIAL_POSITION_Y), TEXTURE, birth, sf::Vector2i(COLUMNS, ROWS), RADIUS, HEALTH), 
	shootClock(0.7f) {
	
	this->time = 0;
	this->spawned = false;
	this->spawn = position;
	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");
}

void HeavyFighter::UpdateLogic(float deltaTime) {
	EnemyEntity::UpdateLogic(deltaTime);

	animator->UpdateLogic(deltaTime);

	time += deltaTime;
	
	if (!spawned) {
		setPosition(getPosition().x, Maths::Lerp(getPosition().y, spawn.y, deltaTime));
		if (Maths::Equals(getPosition().y, spawn.y, START_DISTANCE)) spawned = true;
	}
	else {
		setPosition(Maths::Lerp(getPosition().x, spawn.x + std::cos(time) * CIRCLE_RADIUS, deltaTime), Maths::Lerp(getPosition().y, spawn.y + std::sin(time) * CIRCLE_RADIUS, deltaTime));
	}

	if (shootClock.UpdateLogic(deltaTime)) {
		(new StandardBullet(getPosition() + sf::Vector2f(-32 - 64, 110), sf::Vector2f(0, 1)))->Spawn();
		(new StandardBullet(getPosition() + sf::Vector2f(16 + 64, 110), sf::Vector2f(0, 1)))->Spawn();

		(new StandardBullet(getPosition() + sf::Vector2f(-16, -25), sf::Vector2f(1, 0)))->Spawn();
		(new StandardBullet(getPosition() + sf::Vector2f(-16, -25), sf::Vector2f(-1, 0)))->Spawn();
	}

	if(GetHealth() <= 0) Die();
}