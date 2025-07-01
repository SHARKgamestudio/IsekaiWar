#include "BlendTree.h"

std::string BlendTree::GetCurrent() {
	int closestSlotIndex = 0;
	float smallestDistance = 9999;
	for (int i = 0; i < slots.size(); i++) {
		sf::Vector2f vector = sf::Vector2f(slots[i]->position) - cursor;
		float distance = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
		if (distance < smallestDistance) { closestSlotIndex = i; smallestDistance = distance; }
	}
	return slots[closestSlotIndex]->animatedValue;
}


BlendTree::BlendTree(std::string name, std::vector<Slot*> slots) {
	this->name = name;
	this->slots = slots;
}

void BlendTree::AddSlot(std::string animatedValue, sf::Vector2i position) {
	slots.push_back(new Slot(animatedValue, position));
}

void BlendTree::SetHorizontal(float value) {
	cursor.x = value;
}

void BlendTree::SetVertical(float value) {
	cursor.y = value;
}

void BlendTree::SetCursor(sf::Vector2f cursor) {
	this->cursor = cursor;
}

Slot::Slot(std::string animatedValue, sf::Vector2i position) {
	this->animatedValue = animatedValue;
	this->position = position;
}

Slot::Slot(std::string animatedValue, int x, int y) {
	this->animatedValue = animatedValue;
	this->position = sf::Vector2i(x, y);
}