#pragma once

#include "../Utils/IntervalClock.h"

class HealthModule {
private:
	bool isDead;
	float HP, maxHP;

protected:

	IntervalClock hitClock;
	bool hasTakeDamage;

public:
	HealthModule(float health);

	float GetHealth();
	float GetMaxHealth();
	bool IsDead();

	void virtual TakeDamage(float damage);
	void Heal(float health);
	void UpdateMaxHealth(float newMaxHealth);
};
