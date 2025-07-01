#pragma once

#include "../EnemyEntity.h"
#include "../../../Modules/ShootModule.h"
#include "../../../Modules/AttackModule.h"

class LightFighter : public EnemyEntity, public AttackModule {
private:
	IntervalClock shootClock;
	sf::Vector2f spawn;
	bool spawned;
	float time;

	Animator* animator;
public:
	LightFighter(float x, float y, float birth = 0);
	LightFighter(sf::Vector2f position, float birth = 0);

	void UpdateLogic(float deltaTime) override;
};