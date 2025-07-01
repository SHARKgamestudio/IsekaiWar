#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../LevelScene.h"

#pragma endregion

class Clock;

class Level1 : public LevelScene {
public:
	enum LevelState {
		Playing,
		Win,
		Lose
	};

	LevelState current;

	Clock* clock;
	float highest;

	std::vector<EnemyEntity*> ennemiesPool;

	Level1();

	void Load() override;
	void End();
	void UpdateLogic(float deltaTime) override;
};