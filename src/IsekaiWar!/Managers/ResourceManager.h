#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>

#pragma endregion

class ResourceManager {
private:
	bool loaded;

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Sound> sounds;
	std::map<std::string, sf::Music> musics;
	std::map<std::string, sf::Font> fonts;

	ResourceManager();
	~ResourceManager();

	void LoadTextures(std::string path);
	void LoadSounds(std::string path);
	void LoadMusics(std::string path);
	void LoadFonts(std::string path);
public:
	/// <summary>
	/// Manually loading and displaying engine startup resources.
	/// </summary>
	/// <param name="window"></param>
	void LoadEngineResources(sf::RenderWindow& window);

	/// <summary>
	/// Dynamically loading game resources from the specified directory and its subdirectories.
	/// </summary>
	void LoadGameResources();

	void AddTexture(std::string name, std::string path);
	sf::Texture* GetTexture(std::string name);

	void AddSound(std::string name, std::string path);
	sf::Sound* GetSound(std::string name);

	void AddMusic(std::string name, std::string path);
	sf::Music* GetMusic(std::string name);

	void AddFont(std::string name, std::string path);
	sf::Font* GetFont(std::string name);

	/// <summary>
	/// Returns true once all the dynamic resources have been successfully loaded.
	/// </summary>
	/// <returns></returns>
	bool ResourcesLoaded();

	friend class Managers;
	friend class SoundManager;
};