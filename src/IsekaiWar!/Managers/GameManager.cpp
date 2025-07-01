#include "GameManager.h"

#pragma region External Dependencies

#include <string>
#include <vector>

#pragma endregion

#pragma region Local Dependencies

#include "../Managers.h"
#include "../Utils/OS.h"

#pragma endregion

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

GameManager::GameManager() {
	running = false;
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IsekaiWar!", sf::Style::Fullscreen);
}

GameManager::~GameManager() {
	if (window.isOpen()) {
		window.close();
	}
}

void GameManager::Run() {
	running = true;

	Managers::GetInstance()->ResourceManager->LoadEngineResources(window);

	Managers::GetInstance()->ResourceManager->LoadGameResources();

	Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");

	Managers::GetInstance()->SoundManager->PlayMusic("menu");

	while (window.isOpen() && running) {
		Managers::GetInstance()->InputManager->ClearKeysThisFrame(); // That's so dirty :(
		sf::Time deltaTime = clock.restart();
		HandleEvents();
		UpdateLogic(deltaTime.asSeconds());
		Render();
	}

	window.close();
}

void GameManager::Stop() {
	running = false;
}

void GameManager::HandleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		Managers::GetInstance()->InputManager->UpdateEvents(&event);

		if (event.type == sf::Event::Closed) {
			Stop();
		}
	}

	if (Managers::GetInstance()->InputManager->GetKey("quit")) {
		Stop();
	}

	if (!Managers::GetInstance()->SceneManager->currentScene) {
		Stop();
	}
}


void GameManager::UpdateLogic(float deltaTime) {
	// LOGIC GOES HERE //
	Managers::GetInstance()->SceneManager->UpdateLogic(deltaTime);
	Managers::GetInstance()->InputManager->UpdateInputs();
}

void GameManager::Render() {
	window.clear();

	// RENDERING GOES HERE //
	Managers::GetInstance()->SceneManager->Draw(window);

	window.display();
}