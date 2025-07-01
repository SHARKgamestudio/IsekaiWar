#include "GameOver.h"

#pragma region External Dependencies

#include <iostream>
#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"
#include "../../UI/Components/Image.h"
#include "../../UI/Components/Label.h"

#pragma endregion

GameOver::GameOver() {
	resetCursor = true;
}

void GameOver::Load() {
	Spritesheet* background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("background"), 1, 1);
	Image* background_image = new Image(background_spritesheet);
	background_image->setScale(1, 1);
	background_image->setPosition(1920/2, 1080/2);
	elements.push_back(background_image);

	Label* gameover_label = new Label("GAME OVER");
	gameover_label->SetCharSize(128);
	gameover_label->setPosition(576, 1080 / 8);
	elements.push_back(gameover_label);

	Spritesheet* again_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* again_text = new sf::Text();
	again_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	again_text->setString("TRY AGAIN");
	again_text->setCharacterSize(30);
	Button* again_button = new Button(again_text, again_spritesheet);
	again_button->SetScale(1, 1);
	again_button->setPosition(673, 626);
	elements.push_back(again_button);
	again_text->setOrigin(again_text->getLocalBounds().width / 2, again_text->getLocalBounds().height / 1.1f);

	Spritesheet* menu_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* menu_text = new sf::Text();
	menu_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	menu_text->setString("MAIN MENU");
	menu_text->setCharacterSize(30);
	Button* menu_button = new Button(menu_text, menu_spritesheet);
	menu_button->SetScale(1, 1);
	menu_button->setPosition(1247, 626);
	elements.push_back(menu_button);
	menu_text->setOrigin(menu_text->getLocalBounds().width / 2, menu_text->getLocalBounds().height / 1.1f);



	cursor = new sf::Sprite();
	cursor->setTexture(*Managers::GetInstance()->ResourceManager->GetTexture("cursor"));
	cursor->setScale(1, 1);
	cursor->setOrigin(32, 32);

	resetCursor = true;
}

void GameOver::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	Button* again_button = (Button*)elements[2];
	if (again_button->IsPressed()) {
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("PlayerUI");
		Managers::GetInstance()->SceneManager->LoadLevelAsync("Level1");
	}

	Button* menu_button = (Button*)elements[3];
	if (menu_button->IsPressed()) {
		Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");
	}

	if (Managers::GetInstance()->InputManager->isJoystickConnected()) {
		if (resetCursor) { cursor->setPosition(1920 / 2, 1080 / 2); resetCursor = false; }
		cursor->move(Managers::GetInstance()->InputManager->GetAxis("Horizontal") * dt * 512, Managers::GetInstance()->InputManager->GetAxis("Vertical") * dt * 512);
	}
	else {
		cursor->setPosition(2000, 2000);
		resetCursor = true;
	}
}