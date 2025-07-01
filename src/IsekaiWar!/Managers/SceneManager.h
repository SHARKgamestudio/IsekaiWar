#pragma once

#pragma region External Dependencies

#include <string>
#include <map>

#pragma endregion

#pragma region Local Dependencies

#include "../Scene.h"
#include "../Scenes/LevelScene.h"

#pragma endregion

class Scene;

class SceneManager {
public:

	std::map<std::string, Scene*> scenes;
	std::map<std::string, LevelScene*> levels;

	sf::View menuView;
	sf::View levelView;

	LevelScene* currentLevel;
	Scene* currentScene;

	SceneManager();
	~SceneManager();

	void UpdateLogic(float deltaTime);
	void Draw(sf::RenderWindow& window);

	void ResetScenes();

	void LoadLevel(std::string name);
	void LoadLevelAsync(std::string name);
	void UnloadLevel();
	void UnloadLevelAsync();

	void LoadMenu(std::string name);
	void LoadMenuAsync(std::string name);
	void UnloadMenu();
	void UnloadMenuAsync();
};