#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class MainMenu : public MenuScene {
public:
	bool resetCursor;

	MainMenu();

	void Load();

	void UpdateLogic(float dt) override;
};