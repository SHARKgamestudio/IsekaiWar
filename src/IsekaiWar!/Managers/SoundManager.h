#pragma once

#pragma region External Dependencies

#include <SFML/Audio.hpp>
#include <string>

#pragma endregion

#pragma region Local Dependencies

#include "ResourceManager.h"

#pragma endregion

class SoundManager {
private:
	ResourceManager* resources;

	float global_volume = 100.0f;
	float voices_volume = 100.0f;
	float effects_volume = 100.0f;
	float musics_volume = 100.0f;

	SoundManager();
	~SoundManager();

public:
	sf::Sound* PlaySound(std::string sound, bool loop = false);
	void StopSound(std::string sound);
	sf::Music* PlayMusic(std::string music, bool loop = false);

	void RefreshVolume();

	friend class Managers;
};