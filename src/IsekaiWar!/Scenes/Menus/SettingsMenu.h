#pragma once

#pragma region Local Dependencies

#include "../MenuScene.h"

#pragma endregion

class SettingsMenu : public MenuScene {
public:
	bool resetCursor;

	SettingsMenu();

	void Load();

	bool remappingHorizontalNegative = false;
	bool remappingHorizontalPositive = false;
	bool remappingHorizontalGamepad = false;

	bool remappingVerticalNegative = false;
	bool remappingVerticalPositive = false;
	bool remappingVerticalGamepad = false;

	bool remappingAuto = false;
	bool remappingAutoGamepad = false;

	bool remappingSpe = false;
	bool remappingSpeGamepad = false;

	bool remappingUlt = false;
	bool remappingUltGamepad = false;

	void UpdateLogic(float dt) override;
};