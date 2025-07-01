#include "HealthModule.h"

HealthModule::HealthModule(float health) 
	: hitClock(IntervalClock(0.1f)) {
	isDead = false;
	hasTakeDamage = false;
	maxHP = health;
	HP = health;
}

float HealthModule::GetHealth() {
	return HP;
}

float HealthModule::GetMaxHealth() {
	return maxHP;
}

bool HealthModule::IsDead() {
	return isDead;
}

void HealthModule::TakeDamage(float damage) {
	HP -= damage;

	if (HP < 0) {
		HP = 0; isDead = true;
	}

	hitClock.Restart();
	hasTakeDamage = true;
}

void HealthModule::Heal(float health) {
	HP += health;
	if (HP > maxHP) {
		HP = maxHP;
	}
}

void HealthModule::UpdateMaxHealth(float newMaxHealth) {
	maxHP = newMaxHealth;
}