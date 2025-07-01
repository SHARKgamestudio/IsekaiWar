#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class GameOver : public MenuScene {
public:
	bool resetCursor;

	GameOver();

	void Load();

	void UpdateLogic(float dt) override;
};