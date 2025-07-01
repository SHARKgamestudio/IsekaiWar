#include "HitboxModule.h"
#include "../Entities/CollidableEntity.h"

#pragma region External Dependencies

#include <cmath>
#include <algorithm>

#pragma endregion

HitboxModule::HitboxModule(CollidableEntity* entity, float radius, char statut) {
	this->entity = entity;
	this->radius = radius;
	this->statut = statut;
	hasCollided = false;

	apparence.setOrigin(radius, radius);
	apparence.setRadius(radius);
	apparence.setOutlineThickness(4.f);
	apparence.setFillColor(sf::Color(0, 0, 0, 0));
	apparence.setOutlineColor(sf::Color(100, 250, 50));
}

void HitboxModule::AddToCheck(CollidableEntity* otherEntity) {

	if (statut & 0b01) {
		sf::Vertex* line = new sf::Vertex[2]
		{
			sf::Vertex(sf::Vector2f(entity->getPosition()), sf::Color(100, 250, 50)),
			sf::Vertex(sf::Vector2f(otherEntity->getPosition()), sf::Color(100, 250, 50))
		};

		lines.push_back(line);
	}

	collisionsToCheck.push_back(otherEntity);
}

void HitboxModule::UpdateLines() {
	for (int i = 0; i < lines.size(); i++) {
		lines[i][0].position = entity->getPosition();
		lines[i][1].position = collisionsToCheck[i]->getPosition();
	}
}

void HitboxModule::RemoveToCheck(CollidableEntity* otherEntity) {
	std::_Vector_iterator it = std::find(collisionsToCheck.begin(), collisionsToCheck.end(), otherEntity);

	if (it != collisionsToCheck.end()) {
		int index = std::distance(collisionsToCheck.begin(), it);

		collisionsToCheck.erase(it);

		if (statut & 0b01) {
			lines.erase(lines.begin() + index);
		}
	}
}

void HitboxModule::CheckCollisions() {
	entitiesHit.clear();

	for (CollidableEntity* otherEntity : collisionsToCheck) {

		sf::Vector2f difference = entity->getPosition() - otherEntity->getPosition();
		float distance = sqrtf(difference.y * difference.y + difference.x * difference.x);

		if (distance < radius + otherEntity->radius) {
			entitiesHit.push_back(otherEntity);
		}
	}
}