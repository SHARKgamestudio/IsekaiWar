#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#pragma endregion

struct Animation;

struct Slot {
	std::string animatedValue;
	sf::Vector2i position;

	Slot(std::string animatedValue, sf::Vector2i position);
	Slot(std::string animatedValue, int x, int y);
};

class BlendTree {
private:
	std::string name;
	sf::Vector2f cursor;
	std::vector<Slot*> slots;

	std::string GetCurrent();
public:
	BlendTree(std::string name, std::vector<Slot*> slots = {});
	void AddSlot(std::string animatedValue, sf::Vector2i position);

	void SetHorizontal(float value); void SetVertical(float value);
	void SetCursor(sf::Vector2f cursor);

	friend class Animator;
};