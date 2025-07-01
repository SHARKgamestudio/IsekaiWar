#include "PlayerUI.h"

#pragma region External Dependencies

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Rendering/Spritesheet.h"
#include "../../UI/Components/Button.h"
#include "../../UI/Components/Image.h"
#include "../../UI/Components/Label.h"
#include "../../UI/Components/ProgressBar.h"

#pragma endregion

PlayerUI::PlayerUI() {
}

void PlayerUI::Load() {
	Spritesheet* left_background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-background"), 1, 1);
	left_background_spritesheet->sprite.setOrigin(0, 0);
	Image* left_background_image = new Image(left_background_spritesheet);
	left_background_image->setScale(1, 1);
	left_background_image->setPosition(-55, 0);
	elements.push_back(left_background_image);

	Spritesheet* right_background_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-background"), 1, 1);
	right_background_spritesheet->sprite.setOrigin(0, 0);
	Image* right_background_image = new Image(right_background_spritesheet);
	right_background_image->setScale(1, 1);
	right_background_image->setPosition(1400, 0);
	elements.push_back(right_background_image);

	Spritesheet* maxine_title_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("maxine-title"), 1, 1);
	maxine_title_spritesheet->sprite.setOrigin(0, 0);
	Image* maxine_title_image = new Image(maxine_title_spritesheet);
	maxine_title_image->setScale(1, 1);
	maxine_title_image->setPosition(62, 159);
	elements.push_back(maxine_title_image);

	Label* score_label = new Label("1536", Center);
	score_label->setPosition(1570, 350);
	score_label->SetCharSize(128);
	elements.push_back(score_label);

	Label* xp_label = new Label("XP", Center);
	xp_label->setPosition(1775, 470);
	xp_label->SetCharSize(48);
	elements.push_back(xp_label);

	Label* combo_label = new Label("combo : 4", Center);
	combo_label->setPosition(1572, 550);
	combo_label->SetCharSize(48);
	elements.push_back(combo_label);

	Spritesheet* score_title_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("score-title"), 1, 1);
	score_title_spritesheet->sprite.setOrigin(0, 0);
	Image* score_title_image = new Image(score_title_spritesheet);
	score_title_image->setScale(1, 1);
	score_title_image->setPosition(1510, 159);
	elements.push_back(score_title_image);

	Spritesheet* left_healthbar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-health-progress"), 1, 1);
	Spritesheet* middle_healthbar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-health-progress"), 1, 1);
	Spritesheet* right_healthbar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-health-progress"), 1, 1);

	Spritesheet* left_healthbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-health-background"), 1, 1);
	Spritesheet* middle_healthbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-health-background"), 1, 1);
	Spritesheet* right_healthbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-health-background"), 1, 1);

	healthbar = new ProgressBar(left_healthbar_spritesheet, middle_healthbar_spritesheet, right_healthbar_spritesheet, left_healthbackground_spritesheet, middle_healthbackground_spritesheet, right_healthbackground_spritesheet, 296);
	healthbar->SetFactors(6, 9, 18);
	healthbar->setPosition(125, 343);
	healthbar->SetValue(0);
	this->value = 0;
	elements.push_back(healthbar);

	Spritesheet* left_manabar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-mana-progress"), 1, 1);
	Spritesheet* middle_manabar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-mana-progress"), 1, 1);
	Spritesheet* right_manabar_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-mana-progress"), 1, 1);

	Spritesheet* left_manabackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-mana-background"), 1, 1);
	Spritesheet* middle_manabackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-mana-background"), 1, 1);
	Spritesheet* right_manabackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-mana-background"), 1, 1);

	manabar = new ProgressBar(left_manabar_spritesheet, middle_manabar_spritesheet, right_manabar_spritesheet, left_manabackground_spritesheet, middle_manabackground_spritesheet, right_manabackground_spritesheet, 296);
	manabar->SetFactors(6, 9, 18);
	manabar->setPosition(125, 427);
	manabar->SetValue(0);
	this->value = 0;
	elements.push_back(manabar);

	Spritesheet* health_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("health-icon"), 1, 1);
	health_spritesheet->sprite.setOrigin(0, 0);
	Image* health_image = new Image(health_spritesheet);
	health_image->setScale(1, 1);
	health_image->setPosition(53, 309);
	elements.push_back(health_image);

	Spritesheet* mana_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("mana-icon"), 1, 1);
	mana_spritesheet->sprite.setOrigin(0, 0);
	Image* mana_image = new Image(mana_spritesheet);
	mana_image->setScale(1, 1);
	mana_image->setPosition(60, 390);
	elements.push_back(mana_image);

	#pragma region Auto ProgressBar

	Spritesheet* auto_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("auto-icon"), 1, 1);
	auto_spritesheet->sprite.setOrigin(0, 0);
	Image* auto_image = new Image(auto_spritesheet);
	auto_image->setScale(1, 1);
	auto_image->setPosition(95, 498);
	elements.push_back(auto_image);

	Spritesheet* left_auto_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-spell-progress"), 1, 1);
	left_auto_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* middle_auto_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-spell-progress"), 1, 1);
	middle_auto_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* right_auto_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-spell-progress"), 1, 1);
	right_auto_spritesheet->sprite.setOrigin(0, 0);

	Spritesheet* left_autobackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-spell-background"), 1, 1);
	left_autobackground_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* middle_autobackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-spell-background"), 1, 1);
	middle_autobackground_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* right_autobackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-spell-background"), 1, 1);
	right_autobackground_spritesheet->sprite.setOrigin(0, 0);

	autobar = new ProgressBar(left_auto_spritesheet, middle_auto_spritesheet, right_auto_spritesheet, left_autobackground_spritesheet, middle_autobackground_spritesheet, right_autobackground_spritesheet, 68);
	autobar->SetFactors(0, 0, 0);
	autobar->setOrigin(0, 0);
	autobar->setPosition(95, 498);
	autobar->SetText("");
	autobar->SetValue(0);
	this->value = 0;
	elements.push_back(autobar);

	#pragma endregion

	#pragma region Special ProgressBar

	Spritesheet* special_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("special-icon"), 1, 1);
	special_spritesheet->sprite.setOrigin(0, 0);
	Image* special_image = new Image(special_spritesheet);
	special_image->setScale(1, 1);
	special_image->setPosition(200, 498);
	elements.push_back(special_image);

	Spritesheet* left_special_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-spell-progress"), 1, 1);
	left_special_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* middle_special_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-spell-progress"), 1, 1);
	middle_special_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* right_special_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-spell-progress"), 1, 1);
	right_special_spritesheet->sprite.setOrigin(0, 0);

	Spritesheet* left_specialbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-spell-background"), 1, 1);
	left_specialbackground_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* middle_specialbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-spell-background"), 1, 1);
	middle_specialbackground_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* right_specialbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-spell-background"), 1, 1);
	right_specialbackground_spritesheet->sprite.setOrigin(0, 0);

	specialbar = new ProgressBar(left_special_spritesheet, middle_special_spritesheet, right_special_spritesheet, left_specialbackground_spritesheet, middle_specialbackground_spritesheet, right_specialbackground_spritesheet, 68);
	specialbar->SetFactors(0, 0, 0);
	specialbar->setOrigin(0, 0);
	specialbar->setPosition(200, 498);
	specialbar->SetText("");
	specialbar->SetValue(0);
	this->value = 0;
	elements.push_back(specialbar);

	#pragma endregion

	#pragma region Burst ProgressBar

	Spritesheet* burst_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("burst-icon"), 1, 1);
	burst_spritesheet->sprite.setOrigin(0, 0);
	Image* burst_image = new Image(burst_spritesheet);
	burst_image->setScale(1, 1);
	burst_image->setPosition(305, 498);
	elements.push_back(burst_image);

	Spritesheet* left_burst_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-spell-progress"), 1, 1);
	left_burst_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* middle_burst_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-spell-progress"), 1, 1);
	middle_burst_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* right_burst_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-spell-progress"), 1, 1);
	right_burst_spritesheet->sprite.setOrigin(0, 0);

	Spritesheet* left_burstbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("left-spell-background"), 1, 1);
	left_burstbackground_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* middle_burstbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("middle-spell-background"), 1, 1);
	middle_burstbackground_spritesheet->sprite.setOrigin(0, 0);
	Spritesheet* right_burstbackground_spritesheet = new Spritesheet(Managers::GetInstance()->ResourceManager->GetTexture("right-spell-background"), 1, 1);
	right_burstbackground_spritesheet->sprite.setOrigin(0, 0);

	burstbar = new ProgressBar(left_burst_spritesheet, middle_burst_spritesheet, right_burst_spritesheet, left_burstbackground_spritesheet, middle_burstbackground_spritesheet, right_burstbackground_spritesheet, 68);
	burstbar->SetFactors(0, 0, 0);
	burstbar->setOrigin(0, 0);
	burstbar->setPosition(305, 498);
	burstbar->SetText("");
	burstbar->SetValue(0);
	this->value = 0;
	elements.push_back(burstbar);

	#pragma endregion

	cursor = new sf::Sprite();
	cursor->setTexture(*Managers::GetInstance()->ResourceManager->GetTexture("cursor"));
	cursor->setScale(1, 1);
	cursor->setOrigin(32, 32);
	cursor->setPosition(2000, 2000);
}

void PlayerUI::UpdateLogic(float dt) {
	MenuScene::UpdateLogic(dt);

	if (this->value < 100) { this->value += dt * 64; }
	else { this->value = 0; }
}

void PlayerUI::Draw(sf::RenderWindow& window) {
	MenuScene::Draw(window);

}