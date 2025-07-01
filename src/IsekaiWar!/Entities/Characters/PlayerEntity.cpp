#include "PlayerEntity.h"

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Utils/Maths.h"
#include "../../Scenes/MenuScene.h"
#include "../../UI/Components/ProgressBar.h"
#include "../../UI/Components/Label.h"
#include <iostream>

#pragma endregion

// constructor
#define POSITION_X 400
#define POSITION_Y 400
#define TEXTURE Managers::GetInstance()->ResourceManager->GetTexture("player")
#define COLUMNS 5
#define ROWS 4
#define RADIUS 25.f
#define HEALTH 100.f
#define MAGNITUDE 512.f
#define MANA 100.f

PlayerEntity::PlayerEntity()
	: CharacterEntity(POSITION_X, POSITION_Y, TEXTURE, COLUMNS, ROWS, RADIUS, HEALTH),
	ShootModule(this),
	ManaModule(MANA) {
	this->angle = 0;
	this->inputs = Managers::GetInstance()->InputManager;

	this->animator = new Animator(&spritesheet, { new Animation("idle", 0, 19, 3) });
	this->animator->Play("idle");

	MenuScene* current = (MenuScene*)Managers::GetInstance()->SceneManager->currentScene;
	this->healthbar = dynamic_cast<ProgressBar*>(current->elements[7]);
	this->manabar = dynamic_cast<ProgressBar*>(current->elements[8]);

	this->autobar = dynamic_cast<ProgressBar*>(current->elements[12]);
	this->specialbar = dynamic_cast<ProgressBar*>(current->elements[14]);
	this->burstbar = dynamic_cast<ProgressBar*>(current->elements[16]);

	this->scoretext = dynamic_cast<Label*>(current->elements[3]);
	this->multiplicatortext = dynamic_cast<Label*>(current->elements[5]);
}

void PlayerEntity::UpdateLogic(float deltaTime) {
	LivingEntity::UpdateLogic(deltaTime);
	ShootModule::UpdateLogic(deltaTime);

	this->healthbar->SetValue((this->GetHealth() * 100.0f) / this->GetMaxHealth());
	this->healthbar->SetText(std::to_string((int)this->GetHealth()));

	this->manabar->SetValue((this->GetMana() * 100.0f) / this->GetMaxMana());
	this->manabar->SetText(std::to_string((int)this->GetMana()));

	this->autobar->SetValue((this->clockAuto.GetTime() * 100.0f) / this->clockAuto.maxTime);

	this->specialbar->SetValue((this->clockSpecial.GetTime() * 100.0f) / this->clockSpecial.maxTime);

	this->burstbar->SetValue((this->clockUltime.GetTime() * 100.0f) / this->clockUltime.maxTime);

	this->scoretext->SetText(std::to_string(Managers::GetInstance()->SceneManager->currentLevel->score));

	float multiplicator = Managers::GetInstance()->SceneManager->currentLevel->multiplicator;
	this->multiplicatortext->SetText(std::to_string((int)multiplicator) + "." + std::to_string(static_cast<int>((multiplicator - static_cast<int>(multiplicator)) * 10)));
	
	float horizontal = inputs->GetAxis("Horizontal");
	float vertical = inputs->GetAxis("Vertical");

	sf::Vector2f inputs(horizontal, vertical);

	float magnitude = Maths::Clamp((float)sqrt(pow(inputs.x, 2) + pow(inputs.y, 2)), 0, 1) * MAGNITUDE;

	sf::Vector2f direction = inputs * magnitude;

	float positive = (inputs.x * (float)std::pow(angle / 25 - 1, 2));
	float negative = (inputs.x * (float)std::pow(angle / 25 + 1, 2));

	if (horizontal > 0) {
		angle += positive * deltaTime * 90;
	}
	else if (horizontal < 0) {
		angle += negative * deltaTime * 90;
	}
	else {
		if (angle > 0) { angle += (-std::pow(angle / 25, 0.5f)) * deltaTime * 512; }
		else if (angle < 0) { angle += (std::pow(-angle / 25, 0.5f)) * deltaTime * 512; }
	}

	sf::Vector2f newPos = getPosition();
	
	newPos.x = newPos.x < 0 ? 0 : newPos.x;
	newPos.x = newPos.x > 1920 / 2 - 80 ? 1920 / 2 - 80 : newPos.x;
	newPos.y = newPos.y < 0 ? 0 : newPos.y;
	newPos.y = newPos.y > 1080 ? 1080 : newPos.y;

	setPosition(newPos);

	animator->UpdateLogic(deltaTime);

	if (this->inputs->GetKey("Auto") && canAuto) {
		Managers::GetInstance()->SoundManager->PlaySound("ShootingSpell");
		ShootAuto();
		canAuto = false;
		clockAuto.Restart();
	}

	if (this->inputs->GetKeyDown("Special") && canSpecial) {
		Managers::GetInstance()->SoundManager->PlaySound("ShootingSpell");
		ShootSpecial();
		canSpecial = false;
		clockSpecial.Restart();
	}

	if (this->inputs->GetKeyDown("Ult") && HaveMana()) {
		Managers::GetInstance()->SoundManager->PlaySound("ShootingSpell");
		StartUltime();
		canUltime = false;
		UseMana(64 * deltaTime);
	}
	if (this->inputs->GetKey("Ult") && HaveMana()) {
		Managers::GetInstance()->SoundManager->PlaySound("ShootingSpell");
		UseMana(64 * deltaTime);
	}
	if ((this->inputs->GetKeyUp("Ult") || !HaveMana()) && ultimeBullet != nullptr) {
		StopUltime();
		clockUltime.Restart();
	}

	this->move(direction * deltaTime);
	this->spritesheet.setRotation(angle);
}

void PlayerEntity::TakeDamage(float damage) {
	LivingEntity::TakeDamage(damage);
	// implémentes l'update des pv ici
}

void AddMana() {

}