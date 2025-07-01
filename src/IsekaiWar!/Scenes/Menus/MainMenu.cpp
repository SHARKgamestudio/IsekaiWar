#include "MainMenu.h"

#pragma region External Dependencies

#include <iostream>
#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"
#include "../../UI/Components/Image.h"

#pragma endregion

MainMenu::MainMenu() {
	resetCursor = true;
}

void MainMenu::Load() {
	Spritesheet* background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("background"), 1, 1);
	Image* background_image = new Image(background_spritesheet);
	background_image->setScale(1, 1);
	background_image->setPosition(1920/2, 1080/2);
	elements.push_back(background_image);

	Spritesheet* logo_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("logo"), 1, 1);
	Image* logo_image = new Image(logo_spritesheet);
	logo_image->setScale(1, 1);
	logo_image->setPosition(1920 / 2, 284);
	elements.push_back(logo_image);

	Spritesheet* play_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("play-button"), 1, 4);
	sf::Text* play_text = new sf::Text();
	play_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	play_text->setString("");
	play_text->setCharacterSize(30);
	Button* play_button = new Button(play_text, play_spritesheet);
	play_button->SetScale(1, 1);
	play_button->setPosition(1920 / 2, 598);
	elements.push_back(play_button);

	Spritesheet* settings_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("settings-button"), 1, 4);
	sf::Text* settings_text = new sf::Text();
	settings_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	settings_text->setString("");
	settings_text->setCharacterSize(30);
	Button* settings_button = new Button(settings_text, settings_spritesheet);
	settings_button->SetScale(1, 1);
	settings_button->setPosition(1920 / 2, 748);
	elements.push_back(settings_button);

	Spritesheet* quit_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("quit-button"), 1, 4);
	sf::Text* quit_text = new sf::Text();
	quit_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("font"));
	quit_text->setString("");
	quit_text->setCharacterSize(30);
	Button* quit_button = new Button(quit_text, quit_spritesheet);
	quit_button->SetScale(1, 1);
	quit_button->setPosition(1920/2, 898);
	elements.push_back(quit_button);

	cursor = new sf::Sprite();
	cursor->setTexture(*Managers::GetInstance()->ResourceManager->GetTexture("cursor"));
	cursor->setScale(1, 1);
	cursor->setOrigin(32, 32);

	resetCursor = true;
}

void MainMenu::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	Button* play_button = (Button*)elements[2];
	if (play_button->IsPressed()) {
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("PlayerUI");
		Managers::GetInstance()->SceneManager->LoadLevelAsync("Level1");
	}

	Button* settings_button = (Button*)elements[3];
	if (settings_button->IsPressed()) {
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("SettingsMenu");
	}

	Button* quit_button = (Button*)elements[4];
	if (quit_button->IsPressed()) {
		quit_button->Disable();
		//delete Managers::GetInstance();
		Managers::GetInstance()->GameManager->Stop();
	}

	if (Managers::GetInstance()->InputManager->isJoystickConnected()) {
		if (resetCursor) { cursor->setPosition(1920 / 2, 598); resetCursor = false; }
		cursor->move(Managers::GetInstance()->InputManager->GetAxis("Horizontal") * dt * 512, Managers::GetInstance()->InputManager->GetAxis("Vertical") * dt * 512);
	}
	else {
		cursor->setPosition(2000, 2000);
		resetCursor = true;
	}
}