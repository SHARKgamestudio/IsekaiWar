#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class Win : public MenuScene {
public:
	bool resetCursor;

	Win();

	void Load();

	void UpdateLogic(float dt) override;
};