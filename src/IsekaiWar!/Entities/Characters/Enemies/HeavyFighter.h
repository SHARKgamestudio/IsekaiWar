#pragma once

#include "../EnemyEntity.h"
#include "../../../Modules/ShootModule.h"

class HeavyFighter : public EnemyEntity {
private:
	IntervalClock shootClock;
	sf::Vector2f spawn;
	bool spawned;
	float time;

	Animator* animator;
public:
	HeavyFighter(float x, float y, float birth = 0);
	HeavyFighter(sf::Vector2f position, float birth = 0);

	void UpdateLogic(float deltaTime) override;
};