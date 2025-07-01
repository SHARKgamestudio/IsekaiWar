#pragma once

#include <SFML/Graphics.hpp>

class LootModule {
protected:
	LootModule();

	void Loot(sf::Vector2f pos);
};