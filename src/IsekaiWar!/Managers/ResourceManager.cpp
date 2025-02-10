#include "ResourceManager.h"

#pragma region Local Dependencies

#include "../Utils/Debug.h"
#include "../Utils/OS.h"

#pragma endregion

const std::string DEBUG_PATH = "../../../";

ResourceManager::ResourceManager() {
	loaded = false;
}
ResourceManager::~ResourceManager() {
	textures.clear();

	for (auto& pair : sounds) {
		delete pair.second.getBuffer();
		pair.second.stop();
	}
	sounds.clear();

	for (auto& pair : musics) {
		pair.second.stop();
	}
	musics.clear();

	fonts.clear();

	loaded = false;
}

void ResourceManager::LoadEngineResources(sf::RenderWindow& window) {
	std::string path = "";

#ifdef _DEBUG
	path = OS::getAbsolutePath(DEBUG_PATH) + "res/_engine/";
#else
	path = OS::getExecutablePath() + "/resourcepacks/_engine/";
#endif

	sf::Vector2f windowSize = window.getDefaultView().getSize();

	sf::Texture engineLogoTexture;
	engineLogoTexture.loadFromFile(path + "engine-logo.png");

	sf::Sprite engineLogo;
	engineLogo.setTexture(engineLogoTexture);
	engineLogo.setOrigin(engineLogo.getLocalBounds().width / 2, engineLogo.getLocalBounds().height / 2);
	engineLogo.setPosition(windowSize.x / 2, windowSize.y / 2);

	sf::Font font;
	font.loadFromFile(path + "font.ttf");

	sf::Text loadingText;
	loadingText.setFont(font);
	loadingText.setString("loading resources..");
	loadingText.setCharacterSize(48);
	loadingText.setFillColor(sf::Color::White);
	loadingText.setOrigin(loadingText.getLocalBounds().width / 2, loadingText.getLocalBounds().height / 2);
	loadingText.setPosition(windowSize.x / 2, windowSize.y / 1.2f);

	window.clear();

	window.draw(engineLogo);
	window.draw(loadingText);

	window.display();
}
void ResourceManager::LoadGameResources() {
	std::string root = "";
	std::string subdir = "";

#ifdef _DEBUG
	root = OS::getAbsolutePath(DEBUG_PATH);
	subdir = "res/";
#else
	root = OS::getExecutablePath();
	subdir = "/resourcepacks/";
#endif

	std::string path = root + subdir;

	if (!OS::directoryExists(path)) {
		std::string debug_path = OS::getAbsolutePath(DEBUG_PATH) + "res/";
		OS::createDirectory(path);
		OS::copyDirectory(debug_path, path);
	}

	LoadTextures(path);
	LoadSounds(path);
	LoadMusics(path);
	LoadFonts(path);

	loaded = true;
}

void ResourceManager::LoadTextures(std::string path) {
	std::vector<std::string> assets = OS::getFilesInDirectory(path, ".png");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddTexture(name, asset);
	}
}
void ResourceManager::LoadSounds(std::string path) {
	std::vector<std::string> assets = OS::getFilesInDirectory(path, ".wav");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddSound(name, asset);
	}
}
void ResourceManager::LoadMusics(std::string path) {
	std::vector<std::string> assets = OS::getFilesInDirectory(path, ".wav");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddMusic(name, asset);
	}
}
void ResourceManager::LoadFonts(std::string path) {
	std::vector<std::string> assets = OS::getFilesInDirectory(path, ".ttf");

	for (const std::string& asset : assets) {
		std::string name = asset.substr(asset.find_last_of("/") + 1);
		name = name.substr(0, name.find_last_of("."));
		AddFont(name, asset);
	}
}

void ResourceManager::AddTexture(std::string name, std::string path) {
	bool success = textures[name].loadFromFile(path);
	Debug::Assert(success, "Could not add " + name + "(texture) to resources.");
}
sf::Texture* ResourceManager::GetTexture(std::string name) {
	bool success = textures.contains(name);
	Debug::Assert(success, "Could not retreive " + name + "(texture) from resources.");
	return &textures[name];
}

void ResourceManager::AddSound(std::string name, std::string path) {
	sf::SoundBuffer* buffer = new sf::SoundBuffer;
	buffer->loadFromFile(path);

	sounds[name] = sf::Sound(*buffer);
	bool success = sounds.contains(name);
	Debug::Assert(success, "Could not add " + name + "(sound) to resources.");
}
sf::Sound* ResourceManager::GetSound(std::string name) {
	bool success = sounds.contains(name);
	Debug::Assert(success, "Could not retreive " + name + "(sound) from resources.");

	return &sounds[name];
}

void ResourceManager::AddMusic(std::string name, std::string path) {
	bool success = musics[name].openFromFile(path);
	Debug::Assert(success, "Could not add " + name + "(music) to resources.");
}
sf::Music* ResourceManager::GetMusic(std::string name) {
	bool success = musics.contains(name);
	Debug::Assert(success, "Could not retreive " + name + "(music) from resources.");
	return &musics[name];
}

void ResourceManager::AddFont(std::string name, std::string path) {
	bool success = fonts[name].loadFromFile(path);
	Debug::Assert(success, "Could not add " + name + "(font) to resources.");
}
sf::Font* ResourceManager::GetFont(std::string name) {
	bool success = fonts.contains(name);
	Debug::Assert(success, "Could not retreive " + name + "(font) from resources.");
	return &fonts[name];
}

bool ResourceManager::ResourcesLoaded() {
	return loaded;
}