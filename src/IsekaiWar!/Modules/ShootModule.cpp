#include "ShootModule.h"

#pragma region Local Dependencies

#include "../Entities/Characters/PlayerEntity.h"

#include "../Entities/Bullets/PlayerBullets/AutoBullet.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/NeutralAuto.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/FireAuto.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/WaterAuto.h"
#include "../Entities/Bullets/PlayerBullets/AutoBullets/FireAndWaterAuto.h"

#include "../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../Entities/Bullets/PlayerBullets/UltimeBullet.h"

#pragma endregion

// behaviour
#define RELOAD_AUTO 0.3f
#define RELOAD_SPECIAL 7.f
#define RELOAD_ULTIME 1.f

ShootModule::ShootModule(PlayerEntity* player)
	: clockAuto(IntervalClock(RELOAD_AUTO)),
	clockSpecial(IntervalClock(RELOAD_SPECIAL)),
	clockUltime(IntervalClock(RELOAD_ULTIME))
{
	this->isFire = false;
	this->isWater = false;

	this->isDouble = false;
	this->isTriple = false;
	this->isQuadruple = false;

	currentBullet = StateAuto::Neutral;
	this->ultimeBullet = nullptr;
	this->player = player;

	this->canAuto = true;
	this->canSpecial = true;
	this->canUltime = true;
}

void ShootModule::ShootAuto() {

	sf::Vector2f pos = player->getPosition();

	if (isDouble) {
		GetAutoBullet(sf::Vector2f(pos.x - 20, pos.y), sf::Vector2f(0, -1))->Spawn();
		GetAutoBullet(sf::Vector2f(pos.x + 20, pos.y), sf::Vector2f(0, -1))->Spawn();
	}
	else {
		GetAutoBullet(player->getPosition(), sf::Vector2f(0, -1))->Spawn();
	}

	if (isTriple) {
		GetAutoBullet(player->getPosition(), sf::Vector2f(-1, -2))->Spawn();
		GetAutoBullet(player->getPosition(), sf::Vector2f( 1, -2))->Spawn();
	}

	if (isQuadruple) {
		GetAutoBullet(player->getPosition(), sf::Vector2f(-1, 0))->Spawn();
		GetAutoBullet(player->getPosition(), sf::Vector2f( 1, 0))->Spawn();
		GetAutoBullet(player->getPosition(), sf::Vector2f( 0, 1))->Spawn();
	}
}

AutoBullet* ShootModule::GetAutoBullet(sf::Vector2f pos, sf::Vector2f direction) {
	switch (currentBullet) {

	case StateAuto::Neutral:
		return new NeutralAuto(pos, direction);

	case StateAuto::Fire:
		return new FireAuto(pos, direction);

	case StateAuto::Water:
		return new WaterAuto(pos, direction);

	case StateAuto::FireAndWater:
		return new FireAndWaterAuto(pos, direction);
	}
}

void ShootModule::ShootSpecial() {
	(new SpecialBullet(player->getPosition()))->Spawn();
}

void ShootModule::StartUltime() {
	(ultimeBullet = new UltimeBullet(player->getPosition()))->Spawn();
}

void ShootModule::StopUltime() {
	ultimeBullet->Die();
	ultimeBullet = nullptr;
}

void ShootModule::UpdateLogic(float deltaTime) {
	canAuto = clockAuto.UpdateLogic(deltaTime, false) ? true : canAuto;
	canSpecial = clockSpecial.UpdateLogic(deltaTime, false) ? true : canSpecial;
	canUltime = clockUltime.UpdateLogic(deltaTime, false) ? true : canUltime;
}

void ShootModule::UpdateBullets() {
	if (isFire and isWater) {
		currentBullet = StateAuto::FireAndWater;
		clockAuto.maxTime = 0.2f;
	} 
	else if (isFire) {
		currentBullet = StateAuto::Fire;
	}
	else if (isWater) {
		currentBullet = StateAuto::Water;
		clockAuto.maxTime = 0.2f;
	}
	else {
		currentBullet = StateAuto::Neutral;
	}
}