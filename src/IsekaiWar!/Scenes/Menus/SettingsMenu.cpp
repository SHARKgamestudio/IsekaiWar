#include "SettingsMenu.h"

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

SettingsMenu::SettingsMenu() {
	resetCursor = true;
}

void SettingsMenu::Load() {
	Spritesheet* background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("background"), 1, 1);
	Image* background_image = new Image(background_spritesheet);
	background_image->setScale(1, 1);
	background_image->setPosition(1920/2, 1080/2);
	elements.push_back(background_image);

	Label* gameover_label = new Label("SETTINGS");
	gameover_label->SetCharSize(64);
	gameover_label->setPosition(151, 256);
	elements.push_back(gameover_label);

	Spritesheet* audio_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* audio_text = new sf::Text();
	audio_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	audio_text->setString("AUDIO");
	audio_text->setCharacterSize(8);
	audio_text->setScale(0.55f, 0.55f);
	Button* audio_button = new Button(audio_text, audio_spritesheet);
	audio_button->SetScale(1, 1);
	audio_button->setPosition(256+32, 452);
	elements.push_back(audio_button);
	audio_text->setOrigin(audio_text->getLocalBounds().width / 2, audio_text->getLocalBounds().height / 1.1f);

	Spritesheet* keybinds_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* keybinds_text = new sf::Text();
	keybinds_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	keybinds_text->setString("KEYBINDS");
	keybinds_text->setCharacterSize(8);
	keybinds_text->setScale(0.55f, 0.55f);
	Button* keybinds_button = new Button(keybinds_text, keybinds_spritesheet);
	keybinds_button->SetScale(1, 1);
	keybinds_button->setPosition(256 + 32, 602);
	elements.push_back(keybinds_button);
	keybinds_text->setOrigin(keybinds_text->getLocalBounds().width / 2, keybinds_text->getLocalBounds().height / 1.1f);

	Spritesheet* back_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* back_text = new sf::Text();
	back_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	back_text->setString("BACK");
	back_text->setCharacterSize(8);
	back_text->setScale(0.55f, 0.55f);
	Button* back_button = new Button(back_text, back_spritesheet);
	back_button->SetScale(1, 1);
	back_button->setPosition(256 + 32, 752);
	elements.push_back(back_button);
	back_text->setOrigin(back_text->getLocalBounds().width / 2, back_text->getLocalBounds().height / 1.1f);

	#pragma region Horizontal

	int horizontal_height = 320 + 120;

	Label* horizontal_label = new Label("Horizontal");
	horizontal_label->SetCharSize(28);
	horizontal_label->setPosition(570, 735 - horizontal_height);
	elements.push_back(horizontal_label);

	Spritesheet* neg_kbrd_horizontal_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* neg_kbrd_horizontal_text = new sf::Text();
	neg_kbrd_horizontal_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	neg_kbrd_horizontal_text->setString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[0].negative));
	neg_kbrd_horizontal_text->setCharacterSize(8);
	neg_kbrd_horizontal_text->setScale(0.55f, 0.55f);
	Button* neg_kbrd_horizontal_button = new Button(neg_kbrd_horizontal_text, neg_kbrd_horizontal_spritesheet);
	neg_kbrd_horizontal_button->SetScale(0.75f, 0.75f);
	neg_kbrd_horizontal_button->setPosition(910, 752 - horizontal_height);
	elements.push_back(neg_kbrd_horizontal_button);
	neg_kbrd_horizontal_text->setOrigin(neg_kbrd_horizontal_text->getLocalBounds().width / 2, neg_kbrd_horizontal_text->getLocalBounds().height / 1.1f);

	Spritesheet* pos_kbrd_horizontal_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* pos_kbrd_horizontal_text = new sf::Text();
	pos_kbrd_horizontal_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	pos_kbrd_horizontal_text->setString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[0].positive));
	pos_kbrd_horizontal_text->setCharacterSize(8);
	pos_kbrd_horizontal_text->setScale(0.55f, 0.55f);
	Button* pos_kbrd_horizontal_button = new Button(pos_kbrd_horizontal_text, pos_kbrd_horizontal_spritesheet);
	pos_kbrd_horizontal_button->SetScale(0.75f, 0.75f);
	pos_kbrd_horizontal_button->setPosition(1280, 752 - horizontal_height);
	elements.push_back(pos_kbrd_horizontal_button);
	pos_kbrd_horizontal_text->setOrigin(pos_kbrd_horizontal_text->getLocalBounds().width / 2, pos_kbrd_horizontal_text->getLocalBounds().height / 1.1f);

	Spritesheet* gmpd_horizontal_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* gmpd_horizontal_text = new sf::Text();
	gmpd_horizontal_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	gmpd_horizontal_text->setString(Managers::GetInstance()->InputManager->JoystickToString(Managers::GetInstance()->InputManager->axes[0].joystick) + " Axis");
	gmpd_horizontal_text->setCharacterSize(8);
	gmpd_horizontal_text->setScale(0.55f, 0.55f);
	Button* gmpd_horizontal_button = new Button(gmpd_horizontal_text, gmpd_horizontal_spritesheet);
	gmpd_horizontal_button->SetScale(0.75f, 0.75f);
	gmpd_horizontal_button->setPosition(1650, 752 - horizontal_height);
	elements.push_back(gmpd_horizontal_button);
	gmpd_horizontal_text->setOrigin(gmpd_horizontal_text->getLocalBounds().width / 2, gmpd_horizontal_text->getLocalBounds().height / 1.1f);

	#pragma endregion

	#pragma region Vertical

	int vertical_height = 200 + 120;

	Label* vertical_label = new Label("Vertical");
	vertical_label->SetCharSize(28);
	vertical_label->setPosition(570, 735 - vertical_height);
	elements.push_back(vertical_label);

	Spritesheet* neg_kbrd_vertical_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* neg_kbrd_vertical_text = new sf::Text();
	neg_kbrd_vertical_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	neg_kbrd_vertical_text->setString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[1].negative));
	neg_kbrd_vertical_text->setCharacterSize(8);
	neg_kbrd_vertical_text->setScale(0.55f, 0.55f);
	Button* neg_kbrd_vertical_button = new Button(neg_kbrd_vertical_text, neg_kbrd_vertical_spritesheet);
	neg_kbrd_vertical_button->SetScale(0.75f, 0.75f);
	neg_kbrd_vertical_button->setPosition(910, 752 - vertical_height);
	elements.push_back(neg_kbrd_vertical_button);
	neg_kbrd_vertical_text->setOrigin(neg_kbrd_vertical_text->getLocalBounds().width / 2, neg_kbrd_vertical_text->getLocalBounds().height / 1.1f);

	Spritesheet* pos_kbrd_vertical_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* pos_kbrd_vertical_text = new sf::Text();
	pos_kbrd_vertical_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	pos_kbrd_vertical_text->setString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[1].positive));
	pos_kbrd_vertical_text->setCharacterSize(8);
	pos_kbrd_vertical_text->setScale(0.55f, 0.55f);
	Button* pos_kbrd_vertical_button = new Button(pos_kbrd_vertical_text, pos_kbrd_vertical_spritesheet);
	pos_kbrd_vertical_button->SetScale(0.75f, 0.75f);
	pos_kbrd_vertical_button->setPosition(1280, 752 - vertical_height);
	elements.push_back(pos_kbrd_vertical_button);
	pos_kbrd_vertical_text->setOrigin(pos_kbrd_vertical_text->getLocalBounds().width / 2, pos_kbrd_vertical_text->getLocalBounds().height / 1.1f);

	Spritesheet* gmpd_vertical_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* gmpd_vertical_text = new sf::Text();
	gmpd_vertical_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	gmpd_vertical_text->setString(Managers::GetInstance()->InputManager->JoystickToString(Managers::GetInstance()->InputManager->axes[1].joystick) + " Axis");
	gmpd_vertical_text->setCharacterSize(8);
	gmpd_vertical_text->setScale(0.55f, 0.55f);
	Button* gmpd_vertical_button = new Button(gmpd_vertical_text, gmpd_vertical_spritesheet);
	gmpd_vertical_button->SetScale(0.75f, 0.75f);
	gmpd_vertical_button->setPosition(1650, 752 - vertical_height);
	elements.push_back(gmpd_vertical_button);
	gmpd_vertical_text->setOrigin(gmpd_vertical_text->getLocalBounds().width / 2, gmpd_vertical_text->getLocalBounds().height / 1.1f);

	#pragma endregion

	#pragma region Auto

	int auto_height = 80 + 120;

	Label* auto_label = new Label("Auto");
	auto_label->SetCharSize(28);
	auto_label->setPosition(570, 735 - auto_height);
	elements.push_back(auto_label);

	Spritesheet* auto_kbrd_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* auto_kbrd_text = new sf::Text();
	auto_kbrd_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	auto_kbrd_text->setString("K");
	auto_kbrd_text->setCharacterSize(8);
	auto_kbrd_text->setScale(0.55f, 0.55f);
	Button* auto_kbrd_button = new Button(auto_kbrd_text, auto_kbrd_spritesheet);
	auto_kbrd_button->SetScale(0.75f, 0.75f);
	auto_kbrd_button->setPosition(910, 752 - auto_height);
	elements.push_back(auto_kbrd_button);
	auto_kbrd_text->setOrigin(auto_kbrd_text->getLocalBounds().width / 2, auto_kbrd_text->getLocalBounds().height / 1.1f);

	Spritesheet* auto_gmpd_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* auto_gmpd_text = new sf::Text();
	auto_gmpd_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	auto_gmpd_text->setString("X");
	auto_gmpd_text->setCharacterSize(8);
	auto_gmpd_text->setScale(0.55f, 0.55f);
	Button* auto_gmpd_button = new Button(auto_gmpd_text, auto_gmpd_spritesheet);
	auto_gmpd_button->SetScale(0.75f, 0.75f);
	auto_gmpd_button->setPosition(1280, 752 - auto_height);
	elements.push_back(auto_gmpd_button);
	auto_gmpd_text->setOrigin(auto_gmpd_text->getLocalBounds().width / 2, auto_gmpd_text->getLocalBounds().height / 1.1f);

	#pragma endregion

	#pragma region Special

	int spe_height = -40 + 120;

	Label* spe_label = new Label("Special");
	spe_label->SetCharSize(28);
	spe_label->setPosition(570, 735 - spe_height);
	elements.push_back(spe_label);

	Spritesheet* spe_kbrd_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* spe_kbrd_text = new sf::Text();
	spe_kbrd_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	spe_kbrd_text->setString("L");
	spe_kbrd_text->setCharacterSize(8);
	spe_kbrd_text->setScale(0.55f, 0.55f);
	Button* spe_kbrd_button = new Button(spe_kbrd_text, spe_kbrd_spritesheet);
	spe_kbrd_button->SetScale(0.75f, 0.75f);
	spe_kbrd_button->setPosition(910, 752 - spe_height);
	elements.push_back(spe_kbrd_button);
	spe_kbrd_text->setOrigin(spe_kbrd_text->getLocalBounds().width / 2, spe_kbrd_text->getLocalBounds().height / 1.1f);

	Spritesheet* spe_gmpd_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* spe_gmpd_text = new sf::Text();
	spe_gmpd_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	spe_gmpd_text->setString("A");
	spe_gmpd_text->setCharacterSize(8);
	spe_gmpd_text->setScale(0.55f, 0.55f);
	Button* spe_gmpd_button = new Button(spe_gmpd_text, spe_gmpd_spritesheet);
	spe_gmpd_button->SetScale(0.75f, 0.75f);
	spe_gmpd_button->setPosition(1280, 752 - spe_height);
	elements.push_back(spe_gmpd_button);
	spe_gmpd_text->setOrigin(spe_gmpd_text->getLocalBounds().width / 2, spe_gmpd_text->getLocalBounds().height / 1.1f);

	#pragma endregion

	#pragma region Ult

	int ult_height = -160 + 120;

	Label* ult_label = new Label("Ult");
	ult_label->SetCharSize(28);
	ult_label->setPosition(570, 735 - ult_height);
	elements.push_back(ult_label);

	Spritesheet* ult_kbrd_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* ult_kbrd_text = new sf::Text();
	ult_kbrd_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	ult_kbrd_text->setString("M");
	ult_kbrd_text->setCharacterSize(8);
	ult_kbrd_text->setScale(0.55f, 0.55f);
	Button* ult_kbrd_button = new Button(ult_kbrd_text, ult_kbrd_spritesheet);
	ult_kbrd_button->SetScale(0.75f, 0.75f);
	ult_kbrd_button->setPosition(910, 752 - ult_height);
	elements.push_back(ult_kbrd_button);
	ult_kbrd_text->setOrigin(ult_kbrd_text->getLocalBounds().width / 2, ult_kbrd_text->getLocalBounds().height / 1.1f);

	Spritesheet* ult_gmpd_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("generic-button"), 1, 4);
	sf::Text* ult_gmpd_text = new sf::Text();
	ult_gmpd_text->setFont(*Managers::GetInstance()->ResourceManager->GetFont("barkentina"));
	ult_gmpd_text->setString("R1");
	ult_gmpd_text->setCharacterSize(8);
	ult_gmpd_text->setScale(0.55f, 0.55f);
	Button* ult_gmpd_button = new Button(ult_gmpd_text, ult_gmpd_spritesheet);
	ult_gmpd_button->SetScale(0.75f, 0.75f);
	ult_gmpd_button->setPosition(1280, 752 - ult_height);
	elements.push_back(ult_gmpd_button);
	ult_gmpd_text->setOrigin(ult_gmpd_text->getLocalBounds().width / 2, ult_gmpd_text->getLocalBounds().height / 1.1f);

	#pragma endregion

	cursor = new sf::Sprite();
	cursor->setTexture(*Managers::GetInstance()->ResourceManager->GetTexture("cursor"));
	cursor->setScale(1, 1);
	cursor->setOrigin(32, 32);

	resetCursor = true;
}

void SettingsMenu::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	Button* back_button = (Button*)elements[4];
	if (back_button->IsPressed()) {
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("MainMenu");
	}


#pragma region Horizontal Axis

	Button* keyboard_negative_horizontal_button = (Button*)elements[6];
	if (keyboard_negative_horizontal_button->IsPressed()) {

		remappingHorizontalNegative = true;
	}

	if (remappingHorizontalNegative) {

		if (Managers::GetInstance()->InputManager->MapAxisNegativeKeyboard("Horizontal")) {
			keyboard_negative_horizontal_button->SetString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[0].negative));
			remappingHorizontalNegative = false;
		}
	}

	Button* keyboard_positive_horizontal_button = (Button*)elements[7];
	if (keyboard_positive_horizontal_button->IsPressed()) {

		remappingHorizontalPositive = true;
	}

	if (remappingHorizontalPositive) {

		if (Managers::GetInstance()->InputManager->MapAxisPositiveKeyboard("Horizontal")) {
			keyboard_positive_horizontal_button->SetString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[0].positive));
			remappingHorizontalPositive = false;
		}
	}

	Button* gamepad_horizontal_button = (Button*)elements[8];
	if (gamepad_horizontal_button->IsPressed()) {
		remappingHorizontalGamepad = true;
	}

	if (remappingHorizontalGamepad) {

		if (Managers::GetInstance()->InputManager->MapAxisGamepadInput("Horizontal")) {
			gamepad_horizontal_button->SetString(Managers::GetInstance()->InputManager->JoystickToString(Managers::GetInstance()->InputManager->axes[0].joystick) + " Axis");
			remappingHorizontalGamepad = false;
		}
	}

#pragma endregion

#pragma region Vertical Axis

	Button* keyboard_negative_vertical_button = (Button*)elements[10];
	if (keyboard_negative_vertical_button->IsPressed()) {

		remappingVerticalNegative = true;
	}

	if (remappingVerticalNegative) {

		if (Managers::GetInstance()->InputManager->MapAxisNegativeKeyboard("Vertical")) {
			keyboard_negative_vertical_button->SetString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[1].negative));
			remappingVerticalNegative = false;
		}
	}

	Button* keyboard_positive_vertical_button = (Button*)elements[11];
	if (keyboard_positive_vertical_button->IsPressed()) {

		remappingVerticalPositive = true;
	}

	if (remappingVerticalPositive) {

		if (Managers::GetInstance()->InputManager->MapAxisPositiveKeyboard("Vertical")) {
			keyboard_positive_vertical_button->SetString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->axes[1].positive));
			remappingVerticalPositive = false;
		}
	}

	Button* gamepad_vertical_button = (Button*)elements[12];
	if (gamepad_vertical_button->IsPressed()) {
		remappingVerticalGamepad = true;
	}

	if (remappingVerticalGamepad) {

		if (Managers::GetInstance()->InputManager->MapAxisGamepadInput("Vertical")) {
			gamepad_vertical_button->SetString(Managers::GetInstance()->InputManager->JoystickToString(Managers::GetInstance()->InputManager->axes[1].joystick) + " Axis");
			remappingVerticalGamepad = false;
		}
	}

#pragma endregion
	
#pragma region Auto

	Button* keyboard_auto_button = (Button*)elements[14];
	if (keyboard_auto_button->IsPressed()) {

		remappingAuto = true;
	}

	if (remappingAuto) {
		if (Managers::GetInstance()->InputManager->MapKeyKeyboard("Auto")) {
			keyboard_auto_button->SetString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->keys[4].key));
			remappingAuto = false;
		}
	}

	Button* gamepad_auto_button = (Button*)elements[15];
	if (gamepad_auto_button->IsPressed()) {

		remappingAutoGamepad = true;
	}

	if (remappingAutoGamepad) {
		if (Managers::GetInstance()->InputManager->MapKeyGamepadInput("Auto")) {
			gamepad_auto_button->SetString(Managers::GetInstance()->InputManager->ButtonToString(Managers::GetInstance()->InputManager->keys[4].button));
			remappingAutoGamepad = false;
		}
	}

#pragma endregion

#pragma region Special

	Button* keyboard_spe_button = (Button*)elements[17];
	if (keyboard_spe_button->IsPressed()) {

		remappingSpe = true;
	}

	if (remappingSpe) {
		if (Managers::GetInstance()->InputManager->MapKeyKeyboard("Special")) {
			keyboard_spe_button->SetString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->keys[5].key));
			remappingSpe = false;
		}
	}

	Button* gamepad_spe_button = (Button*)elements[18];
	if (gamepad_spe_button->IsPressed()) {

		remappingSpeGamepad = true;
	}

	if (remappingSpeGamepad) {
		if (Managers::GetInstance()->InputManager->MapKeyGamepadInput("Special")) {
			gamepad_spe_button->SetString(Managers::GetInstance()->InputManager->ButtonToString(Managers::GetInstance()->InputManager->keys[5].button));
			remappingSpeGamepad = false;
		}
	}

#pragma endregion

#pragma region Ult

	Button* keyboard_ult_button = (Button*)elements[20];
	if (keyboard_ult_button->IsPressed()) {

		remappingUlt = true;
	}

	if (remappingUlt) {
		if (Managers::GetInstance()->InputManager->MapKeyKeyboard("Ult")) {
			keyboard_ult_button->SetString(Managers::GetInstance()->InputManager->KeyToString(Managers::GetInstance()->InputManager->keys[6].key));
			remappingUlt = false;
		}
	}

	Button* gamepad_ult_button = (Button*)elements[21];
	if (gamepad_ult_button->IsPressed()) {

		remappingUltGamepad = true;
	}

	if (remappingUltGamepad) {
		if (Managers::GetInstance()->InputManager->MapKeyGamepadInput("Ult")) {
			gamepad_ult_button->SetString(Managers::GetInstance()->InputManager->ButtonToString(Managers::GetInstance()->InputManager->keys[6].button));
			remappingUltGamepad = false;
		}
	}

#pragma endregion

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (Managers::GetInstance()->InputManager->isJoystickConnected()) {
		if (resetCursor) { cursor->setPosition(256 + 32, 752); resetCursor = false; }
		cursor->move(Managers::GetInstance()->InputManager->GetAxis("Horizontal") * dt * 512, Managers::GetInstance()->InputManager->GetAxis("Vertical") * dt * 512);
	}
	else {
		cursor->setPosition(2000, 2000);
		resetCursor = true;
	}
}