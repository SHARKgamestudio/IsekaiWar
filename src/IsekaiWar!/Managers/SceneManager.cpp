#include "SceneManager.h"

#pragma region Local Dependencies

#include "../Managers.h"
#include "../Scenes/Levels/Level1.h"
#include "../Scenes/Menus/MainMenu.h"
#include "../Scenes/Menus/SettingsMenu.h"
#include "../Scenes/Menus/GameOver.h"
#include "../Scenes/Menus/PlayerUI.h"
#include "../Scenes/Menus/Win.h"
#include "../Scenes/MenuScene.h"

#pragma endregion

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
SceneManager::SceneManager() :
	levelView(sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT))),
	menuView(sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT))) {
	
	currentLevel = nullptr;
	currentScene = nullptr;

	scenes["GameOver"] = new GameOver();
	scenes["Win"] = new Win();
	scenes["MainMenu"] = new MainMenu();
	scenes["PlayerUI"] = new PlayerUI();
	scenes["SettingsMenu"] = new SettingsMenu();
	levels["Level1"] = new Level1();

	levelView.move(-WINDOW_WIDTH / 4, 0);
}

SceneManager::~SceneManager() {

	for (auto& pair : scenes) {
		delete pair.second;
	}
	scenes.clear();

	for (auto& pair : levels) {
		delete pair.second;
	}
	levels.clear();

	currentLevel = nullptr;
	currentScene = nullptr;
}

void SceneManager::LoadMenu(std::string name) {
	currentScene = scenes[name];
	currentLevel = nullptr;

	currentScene->Load();
}
void SceneManager::LoadMenuAsync(std::string name) {
	currentScene = scenes[name];

	currentScene->Load();
}
void SceneManager::UnloadMenu() {
	currentLevel = nullptr;
	currentScene = nullptr;
}
void SceneManager::UnloadMenuAsync() {
	currentScene = nullptr;
}

void SceneManager::LoadLevel(std::string name) {

	currentLevel = levels[name];
	currentScene = nullptr;

	currentLevel->Load();
}
void SceneManager::LoadLevelAsync(std::string name) {
	currentLevel = levels[name];

	currentLevel->Load();
}
void SceneManager::UnloadLevel() {
	currentLevel = nullptr;
	currentScene = nullptr;
}
void SceneManager::UnloadLevelAsync() {
	currentLevel = nullptr;
}

void SceneManager::UpdateLogic(float deltaTime) {
	if (currentLevel != nullptr) {
		currentLevel->UpdateLogic(deltaTime);
	}

	if (currentScene != nullptr) {
		currentScene->UpdateLogic(deltaTime);
	}
}
void SceneManager::Draw(sf::RenderWindow& window) {

	if (currentLevel != nullptr) {
		Managers::GetInstance()->GameManager->window.setView(levelView);
		currentLevel->Draw(window);
	}

	if (currentScene != nullptr) {
		Managers::GetInstance()->GameManager->window.setView(menuView);
		currentScene->Draw(window);
	}
}

void SceneManager::ResetScenes() {
	scenes["GameOver"] = new GameOver();
	scenes["Win"] = new Win();
	scenes["MainMenu"] = new MainMenu();
	scenes["PlayerUI"] = new PlayerUI();
	levels["Level1"] = new Level1();
}
