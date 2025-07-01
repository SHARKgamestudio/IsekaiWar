#pragma once

class ManaModule {
private:
	bool haveMana;
	float mana, maxMana;

protected:

	bool hasUseMana;

public:
	ManaModule(float mana);

	float GetMana();
	float GetMaxMana();
	bool HaveMana();

	void virtual UseMana(float damage);
	void ObtainMana(float health);
	void UpdateMaxMana(float newMaxMana);
};