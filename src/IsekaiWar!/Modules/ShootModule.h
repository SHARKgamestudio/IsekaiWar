#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils/IntervalClock.h"

enum StateAuto {
	Neutral,
	Fire,
	Water,
	FireAndWater,
};

class PlayerEntity;
class UltimeBullet;
class AutoBullet;

class ShootModule {
protected:

	IntervalClock clockAuto;
	IntervalClock clockSpecial;
	IntervalClock clockUltime;

	PlayerEntity* player;
	UltimeBullet* ultimeBullet;
	int currentBullet;

	bool canAuto;
	bool canSpecial;
	bool canUltime;

public:

	// Elements
	bool isFire;
	bool isWater;

	// Paterns
	bool isDouble;
	bool isTriple;
	bool isQuadruple;

	ShootModule(PlayerEntity* player);

	void ShootAuto();
	AutoBullet* GetAutoBullet(sf::Vector2f pos, sf::Vector2f direction);

	void ShootSpecial();
	void StartUltime();
	void StopUltime();

	void UpdateLogic(float deltaTime);
	void UpdateBullets();
};