#pragma once

#include "../EnemyEntity.h"
#include "../../../Modules/ShootModule.h"

class StandardFighterVar2 : public EnemyEntity {
private:
	IntervalClock shootClock;
	sf::Vector2f spawn;
	bool spawned;
	float time;

	Animator* animator;
public:
	StandardFighterVar2(float x, float y, float birth = 0, bool right = true);
	StandardFighterVar2(sf::Vector2f position, float birth = 0, bool right = true);

	void UpdateLogic(float deltaTime) override;
};