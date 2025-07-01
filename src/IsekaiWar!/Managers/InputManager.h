#pragma once

#pragma region External Dependencies

#include <SFML/Graphics.hpp>
#include <magic_enum.hpp>
#include <string>
#include <map>

#pragma endregion

enum State {
	None,
	Pressed,
	Hold,
	Released
};

class Axis {
public:
	std::string name;

	sf::Keyboard::Key negative;
	sf::Keyboard::Key positive;

	sf::Joystick::Axis joystick;

	float value = 0;

	Axis(std::string name, sf::Keyboard::Key negative, sf::Keyboard::Key positive, sf::Joystick::Axis joystick);
};

class Key {
public:
	std::string name;

	sf::Keyboard::Key key;
	unsigned int button;

	bool hold;
	State current;

	Key(std::string name, sf::Keyboard::Key key, unsigned int button);
};

enum XboxButton {
	A = 0,
	B = 1,
	X = 2,
	Y = 3,
	LB = 4,
	RB = 5,
	Back = 6,
	Start = 7,
	Guide = 8,
	LeftStick = 9,
	RightStick = 10
};

class InputManager {
private:
	std::vector<sf::Keyboard::Key> keysPressed; // WIP please remove, it's garbage (LIKE EVERYTHING ELSE IN THIS FUCKING ENGINE)

	sf::Event* event;
	bool joystickConnected = false;

	float GetRawAxis(std::string name);
	State GetRawKey(std::string name);

	float GetJoystickValue(sf::Joystick::Axis axis);
	bool GetKeyValue(sf::Keyboard::Key key);
public:
	std::vector<Axis> axes{
		Axis("Horizontal", sf::Keyboard::Q, sf::Keyboard::D, sf::Joystick::X),
		Axis("Vertical", sf::Keyboard::Z, sf::Keyboard::S, sf::Joystick::Y)
	};

	std::vector<Key> keys{
		Key("quit", sf::Keyboard::Escape, 8),
		Key("Confirm", sf::Keyboard::K, 0),
		Key("Confirm", sf::Keyboard::K, 0),
		Key("Cancel", sf::Keyboard::K, 1),

		Key("Auto", sf::Keyboard::K, 2),
		Key("Special", sf::Keyboard::L, 0),
		Key("Ult", sf::Keyboard::M, 5)
	};

	~InputManager();

	bool isJoystickConnected();

	void UpdateInputs();
	void UpdateEvents(sf::Event* event);

	float GetAxis(std::string name);
	
	bool GetKeyDown(std::string name);
	bool GetKey(std::string name);
	bool GetKeyUp(std::string name);

	bool MapAxisNegativeKeyboard(std::string name);
	bool MapAxisPositiveKeyboard(std::string name);
	bool MapAxisGamepadInput(std::string name);

	bool MapKeyKeyboard(std::string name);
	bool MapKeyGamepadInput(std::string name);

	std::string KeyToString(sf::Keyboard::Key key);
	std::string ButtonToString(unsigned int button);
	std::string JoystickToString(sf::Joystick::Axis axis);

	void ClearKeysThisFrame();
};