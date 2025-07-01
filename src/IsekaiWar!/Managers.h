#pragma once

#pragma region Local Dependencies

#include "Managers/GameManager.h"
#include "Managers/InputManager.h"
#include "Managers/ResourceManager.h"
#include "Managers/SceneManager.h"
#include "Managers/SoundManager.h"

#pragma endregion

class Managers {
private:
	static Managers* Instance;
public:
	Managers();
	~Managers();

	GameManager* GameManager;
	InputManager* InputManager;
	ResourceManager* ResourceManager;
	SceneManager* SceneManager;
	SoundManager* SoundManager;

	static Managers* GetInstance();
};