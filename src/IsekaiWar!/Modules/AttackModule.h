#pragma once

class LivingEntity;

class AttackModule {
private:
	float damage;

public:
	AttackModule(float damage);
	void Attack(LivingEntity* entity);
	void Attack(LivingEntity* entity, float deltatime);
};