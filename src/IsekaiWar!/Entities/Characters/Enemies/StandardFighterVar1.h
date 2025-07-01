#pragma once

#include "../EnemyEntity.h"
#include "../../../Modules/ShootModule.h"

class StandardFighterVar1 : public EnemyEntity {
private:
	IntervalClock shootClock;
	sf::Vector2f spawn;
	bool spawned;
	float time;

	Animator* animator;
public:
	StandardFighterVar1(float x, float y, float birth = 0);
	StandardFighterVar1(sf::Vector2f position, float birth = 0);

	void UpdateLogic(float deltaTime) override;
};