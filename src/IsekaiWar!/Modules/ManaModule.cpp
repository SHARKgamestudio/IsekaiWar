#include "ManaModule.h"

ManaModule::ManaModule(float maxMana) {
	this->haveMana = false;
	this->hasUseMana = false;
	this->mana = 0;
	this->maxMana = maxMana;
}

float ManaModule::GetMana() {
	return mana;
}

float ManaModule::GetMaxMana() {
	return maxMana;
}

bool ManaModule::HaveMana() {
	return haveMana;
}

void ManaModule::UseMana(float mana) {
	this->mana -= mana;

	if (this->mana < 0) {
		this->mana = 0; haveMana = false;
	}

	hasUseMana = true;
}

void ManaModule::ObtainMana(float mana) {
	this->mana += mana;
	if (this->mana > maxMana) {
		this->mana = maxMana;
	}
	haveMana = true;
}

void ManaModule::UpdateMaxMana(float newMaxMana) {
	maxMana = newMaxMana;
}