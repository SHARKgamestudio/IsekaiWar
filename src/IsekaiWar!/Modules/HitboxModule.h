#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <vector>

#pragma endregion

class CollidableEntity;

class HitboxModule {
public:
	CollidableEntity* entity;
	std::vector<CollidableEntity*> collisionsToCheck;
	std::vector<CollidableEntity*> entitiesHit;
	sf::CircleShape apparence;
	std::vector<sf::Vertex*> lines;
	float radius;
	bool hasCollided;

	char statut; // collisions, hitbox

	HitboxModule(CollidableEntity* entity, float radius, char statut);

	void AddToCheck(CollidableEntity* otherEntity);
	void RemoveToCheck(CollidableEntity* otherEntity);
	void virtual UpdateLines();
	void virtual CheckCollisions();
};