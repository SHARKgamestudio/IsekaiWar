#include "Level1.h"

#pragma region External Dependencies

#include <iostream>

#pragma endregion

#pragma region Local Dependencies

#include "../../Managers.h"
#include "../../Entities/BackgroundEntity.h"
#include "../../Entities/Bullets/PlayerBullets/SpecialBullet.h"
#include "../../Entities/Characters/Enemies/StandardFighterVar0.h"
#include "../../Entities/Characters/Enemies/StandardFighterVar1.h"
#include "../../Entities/Characters/Enemies/StandardFighterVar2.h"
#include "../../Entities/Characters/Enemies/LightFighter.h"
#include "../../Entities/Characters/Enemies/HeavyFighter.h"

#include "../../Utils/Clock.h"

#pragma endregion

Level1::Level1() {
	current = LevelState::Playing;
	clock = new Clock();
	highest = 0;
	score = 0;
	multiplicator = 1.f;
}

void Level1::Load() {
	LevelScene::Load();

	Managers::GetInstance()->SoundManager->PlayMusic("music");

	clock = new Clock(true);

	ennemiesPool = {
		// WAVE 1
		new StandardFighterVar0(736, 125, 0.0f),
		new StandardFighterVar1(471, 345, 0.0f),
		new StandardFighterVar1(142, 248, 0.0f),

		// WAVE 2
		new StandardFighterVar0(640, 300, 1.f),
		new StandardFighterVar0(300, 500, 1.f),
		new StandardFighterVar1(550, 500, 1.0f),
		new StandardFighterVar0(236, 125, 1.f),

		// WAVE 3
		new StandardFighterVar0(150, 300, 2.f),
		new StandardFighterVar0(300, 400, 2.f),
		new HeavyFighter(450, 300, 2.f),
		new StandardFighterVar0(600, 400, 2.f),
		new StandardFighterVar0(750, 300, 2.f),

		// WAVE 4
		new StandardFighterVar0(150, 300, 3.f),
		new StandardFighterVar0(300, 400, 3.f),
		new StandardFighterVar0(450, 300, 3.f),
		new StandardFighterVar0(600, 400, 3.f),
		new StandardFighterVar0(750, 300, 3.f),
		new StandardFighterVar1(150, 500, 3.f),
		new StandardFighterVar0(300, 600, 3.f),
		new StandardFighterVar1(450, 500, 3.f),
		new StandardFighterVar0(600, 600, 3.f),
		new StandardFighterVar1(750, 500, 3.f),

		// WAVE 5
		new LightFighter(100, 861, 4.f),
		new LightFighter(164, 524, 4.f),
		new LightFighter(617, 168, 4.f),
		new LightFighter(168, 752, 4.f),
		new LightFighter(314, 551, 4.f),
		new LightFighter(364, 413, 4.f),
		new LightFighter(412, 871, 4.f),
		new LightFighter(945, 371, 4.f),
		new LightFighter(453, 674, 4.f),

		// WAVE 6
		new HeavyFighter(300, 500, 5.f),
		new HeavyFighter(600, 500, 5.f),
		new StandardFighterVar0(150, 300, 5.f),
		new StandardFighterVar0(450, 300, 5.f),
		new StandardFighterVar0(750, 300, 5.f),
		new StandardFighterVar0(150, 900, 5.f),
		new StandardFighterVar0(900, 900, 5.f),
		new StandardFighterVar0(100, 700, 5.f),
		new StandardFighterVar0(950, 700, 5.f),

		// WAVE 7
		new StandardFighterVar2(100, 200, 6.f, true),
		new StandardFighterVar2(100, 400, 6.f, true),
		new StandardFighterVar2(100, 600, 6.f, true),
		new StandardFighterVar2(100, 800, 6.f, true),
		new StandardFighterVar2(900, 300, 6.f, false),
		new StandardFighterVar2(900, 500, 6.f, false),
		new StandardFighterVar2(900, 700, 6.f, false),
		new StandardFighterVar2(900, 900, 6.f, false),
		new StandardFighterVar0(350, 200, 6.f),
		new StandardFighterVar0(600, 200, 6.f),
		new StandardFighterVar0(850, 200, 6.f),
		new StandardFighterVar0(350, 400, 6.f),
		new StandardFighterVar0(600, 400, 6.f),
		new StandardFighterVar0(350, 400, 6.f),

		// WAVE 8
		new HeavyFighter(150, 300, 7.f),
		new HeavyFighter(300, 400, 7.f),
		new HeavyFighter(450, 300, 7.f),
		new HeavyFighter(600, 400, 7.f),
		new HeavyFighter(750, 300, 7.f),
		new HeavyFighter(150, 500, 7.f),
		new HeavyFighter(300, 600, 7.f),
		new HeavyFighter(450, 500, 7.f),
		new HeavyFighter(600, 600, 7.f),
		new HeavyFighter(750, 500, 7.f),
		new LightFighter(150, 300, 7.f),
		new LightFighter(300, 400, 7.f),
		new LightFighter(450, 300, 7.f),
		new LightFighter(600, 400, 7.f),
		new LightFighter(750, 300, 7.f),
		new LightFighter(150, 500, 7.f),
		new LightFighter(300, 600, 7.f),
		new LightFighter(450, 500, 7.f),
		new LightFighter(600, 600, 7.f),
		new LightFighter(750, 500, 7.f),
	};

	for (int i = 0; i < ennemiesPool.size(); i++) {
		if (ennemiesPool[i]->birth > highest) highest = ennemiesPool[i]->birth;
	}

	backgrounds.push_back(new BackgroundEntity(Managers::GetInstance()->ResourceManager->GetTexture("forest"), sf::Vector2f(600, 800), sf::Vector2f(1400, 1200)));
	player = new PlayerEntity();
	current = Playing;
}

void Level1::End() {
	// EXECUTE AT THE END OF THE LEVEL //

	if (current == Lose) {
		Managers::GetInstance()->SoundManager->StopSound("BirdFlaps");
		Managers::GetInstance()->SoundManager->StopSound("MidAirLoop");
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("GameOver");
	}
	else if (current == Win) {
		Managers::GetInstance()->SoundManager->StopSound("BirdFlaps");
		Managers::GetInstance()->SoundManager->StopSound("MidAirLoop");
		Managers::GetInstance()->SceneManager->currentLevel->score = score;
		//Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenuAsync("Win");
		Managers::GetInstance()->SceneManager->ResetScenes();
		Managers::GetInstance()->SceneManager->LoadMenu("Win");
	}
}

void Level1::UpdateLogic(float deltaTime) {
	LevelScene::UpdateLogic(deltaTime);

	clock->UpdateLogic(deltaTime);

	float time = clock->GetTime();

	for (int i = 0; i < ennemiesPool.size(); i++) {
		if (time >= float(ennemiesPool[i]->birth)) {
			SpawnEnnemy(ennemiesPool[i]);
			ennemiesPool.erase(ennemiesPool.begin() + i);
		}
	}

	if (player->IsDead()) {
		current = Lose;
		End();
	}

	if (ennemies.size() == 0) {
		if (time >= highest) {
			current = Win;
			End();	
		}

		clock->Resume();
	}
	else { clock->Pause(); }
}