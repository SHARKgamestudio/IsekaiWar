#include "SoundManager.h"

#include "../Managers.h"

SoundManager::SoundManager() {
	resources = Managers::GetInstance()->ResourceManager;
}

SoundManager::~SoundManager() {
	resources = nullptr;
}

sf::Sound* SoundManager::PlaySound(std::string sound, bool loop) {
	resources->sounds[sound].setVolume(global_volume * effects_volume / 100.0f);
	resources->sounds[sound].setLoop(loop);
	resources->sounds[sound].play();

	return &resources->sounds[sound];
}

void SoundManager::StopSound(std::string sound) {
	resources->sounds[sound].stop();
}

sf::Music* SoundManager::PlayMusic(std::string music, bool loop) {
	for (auto& element : resources->musics) {
		element.second.stop();
	}

	resources->musics[music].setVolume(global_volume * musics_volume / 100.0f);
	resources->musics[music].setLoop(loop);
	resources->musics[music].play();
	return &resources->musics[music];
}

void SoundManager::RefreshVolume() {
	for (auto& element : resources->sounds) {
		element.second.setVolume(global_volume * effects_volume / 100.0f);
	}
	for (auto& element : resources->musics) {
		element.second.setVolume(global_volume * musics_volume / 100.0f);
	}
}