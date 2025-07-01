#include "AttackModule.h"

#pragma region Local Dependencies

#include "../Entities/LivingEntity.h"

#pragma endregion

AttackModule::AttackModule(float damage) {
	this->damage = damage;
}

void AttackModule::Attack(LivingEntity* entity) {
	entity->TakeDamage(damage);
}

void AttackModule::Attack(LivingEntity* entity, float deltatime) {
	entity->TakeDamage(damage * deltatime);
}