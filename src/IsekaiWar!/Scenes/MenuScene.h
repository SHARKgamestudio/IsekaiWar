#pragma once

#pragma region External Dependencies

#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"

#pragma endregion

class UIComponent;
class Sprite;

class MenuScene : public Scene {
protected:
	sf::Sprite* cursor;

public:
	std::vector<UIComponent*> elements;

	~MenuScene();

	void virtual Load();
	void virtual UpdateLogic(float dt);
	void virtual Draw(sf::RenderWindow& window) override;
};