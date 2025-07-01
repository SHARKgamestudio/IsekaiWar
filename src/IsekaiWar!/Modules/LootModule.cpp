#include "LootModule.h"

#pragma region Local Dependencies

#include "../Entities/PowerUps/FireBook.h"
#include "../Entities/PowerUps/WaterBook.h"
#include "../Entities/PowerUps/DoubleParchment.h"
#include "../Entities/PowerUps/TripleParchment.h"
#include "../Entities/PowerUps/QuadrupleParchment.h"

#pragma endregion

// add a looting table if we need
LootModule::LootModule() {
}

void LootModule::Loot(sf::Vector2f pos) {

	int randint = rand() % 100;

	if (randint <= 10) {
		int randint = rand() % 100;

		if (randint <= 30) {
			(new FireBook(pos))->Spawn();
		}
		else if (randint <= 60) {
			(new WaterBook(pos))->Spawn();
		}
		else if (randint <= 73) {
			(new DoubleParchment(pos))->Spawn();
		}
		else if (randint <= 86) {
			(new TripleParchment(pos))->Spawn();
		}
		else {
			(new QuadrupleParchment(pos))->Spawn();
		}
	}
}