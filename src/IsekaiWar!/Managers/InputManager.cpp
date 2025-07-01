#include "InputManager.h"

#pragma region Local Dependencies

#include "../Utils/Maths.h"
#include <chrono>
#include <iostream>

#pragma endregion

#define ACCURACY 4

InputManager::~InputManager() {
	axes.clear();
	keys.clear();
}

Axis::Axis(std::string name, sf::Keyboard::Key negative, sf::Keyboard::Key positive, sf::Joystick::Axis joystick) {
	this->name = name;
	this->negative = negative;
	this->positive = positive;
	this->joystick = joystick;
}

Key::Key(std::string name, sf::Keyboard::Key key, unsigned int button) {
	this->name = name;
	this->key = key;
	this->button = button;
	this->hold = false;
	this->current = None;
}

float InputManager::GetRawAxis(std::string name) {
	for (int i = 0; i < axes.size(); i++) {
		if (axes[i].name == name) {
			return axes[i].value;
		}
	}
	return 0;
}

State InputManager::GetRawKey(std::string name) {
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i].name == name) {
			return keys[i].current;
		}
	}
	return None;
}

float InputManager::GetJoystickValue(sf::Joystick::Axis axis) {
	float raw = sf::Joystick::getAxisPosition(0, axis) / 100;
	return raw < 0.025f && raw > -0.025f ? 0 : raw;
}

bool InputManager::GetKeyValue(sf::Keyboard::Key key) {
	return sf::Keyboard::isKeyPressed(key);
}

bool InputManager::isJoystickConnected() {
	return joystickConnected;
}

void InputManager::UpdateInputs() {

	#pragma region UpdateLogic Axes

	for (int i = 0; i < axes.size(); i++) {
		if (joystickConnected) {
				axes[i].value = GetJoystickValue(axes[i].joystick);
		}
		else {
			axes[i].value = GetKeyValue(axes[i].negative) ? -1.0f
			: (GetKeyValue(axes[i].positive) ? 1.0f : 0.0f);
		}
	}

	#pragma endregion

	#pragma region UpdateLogic Keys

	for (int i = 0; i < keys.size(); i++) {
		if (joystickConnected) {
			if (sf::Joystick::isButtonPressed(0, keys[i].button)) {
				keys[i].current = keys[i].hold ? Hold : Pressed;
				keys[i].hold = true;
			} else {
				keys[i].current = keys[i].hold ? Released : None;
				keys[i].hold = false;
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(keys[i].key)) {
				keys[i].current = keys[i].hold ? Hold : Pressed;
				keys[i].hold = true;
			}
			else {
				keys[i].current = keys[i].hold ? Released : None;
				keys[i].hold = false;
			}
		}
	}

	#pragma endregion

}

void InputManager::UpdateEvents(sf::Event* event) {
	if (event->type == sf::Event::KeyPressed) {
		keysPressed.push_back(event->key.code);
	}

	if (event->type == sf::Event::JoystickConnected || sf::Joystick::isConnected(0))
		joystickConnected = true;
	if (event->type == sf::Event::JoystickDisconnected)
		joystickConnected = false;

	this->event = event;
}

float InputManager::GetAxis(std::string name) {
	return Maths::Round(GetRawAxis(name), ACCURACY);
}

bool InputManager::GetKeyDown(std::string name) {
	return GetRawKey(name) == Pressed;
}

bool InputManager::GetKey(std::string name) {
	return GetRawKey(name) == Hold;
}

bool InputManager::GetKeyUp(std::string name) {
	return GetRawKey(name) == Released;
}

bool InputManager::MapAxisNegativeKeyboard(std::string name) {
	for (int i = 0; i < axes.size(); i++) {
		if (axes[i].name == name) {
			for (sf::Keyboard::Key key : keysPressed) {
				axes[i].negative = key;
				return true;
			}
		}
	}

	return false;
}

bool InputManager::MapAxisPositiveKeyboard(std::string name)
{
	for (int i = 0; i < axes.size(); i++) {
		if (axes[i].name == name) {
			for (sf::Keyboard::Key key : keysPressed) {
				axes[i].positive = key;
				return true;
			}
		}
	}

	return false;
}

bool InputManager::MapAxisGamepadInput(std::string name) {
	if (!joystickConnected) return true;

	const float deadZone = 15.0f;

	for (int i = 0; i < axes.size(); i++) {
		if (axes[i].name == name) {
			for (int axis = 0; axis < sf::Joystick::AxisCount; axis++) {
				auto sfAxis = static_cast<sf::Joystick::Axis>(axis);

				if (sf::Joystick::hasAxis(0, sfAxis)) {
					float value = sf::Joystick::getAxisPosition(0, sfAxis);
					if (std::abs(value) > deadZone) {
						axes[i].joystick = sfAxis;
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool InputManager::MapKeyKeyboard(std::string name) {
	for (int i = 0; i < keys.size(); i++) {
		if (keys[i].name == name) {
			for (sf::Keyboard::Key key : keysPressed) {
				keys[i].key = key;
				return true;
			}
		}
	}

	return false;
}


bool InputManager::MapKeyGamepadInput(std::string name)
{
	if (!joystickConnected) return true;

	for (int i = 0; i < keys.size(); i++) {
		if (keys[i].name == name) {
			for (unsigned int button = 0; button < sf::Joystick::ButtonCount; button++) {
				bool value = sf::Joystick::isButtonPressed(0, button);
				if (value) {
					keys[i].button = button;
					return true;
				}
			}
		}
	}

	return false;
}


std::string InputManager::KeyToString(sf::Keyboard::Key key) {
	return std::string(magic_enum::enum_name(key));
}

std::string InputManager::ButtonToString(unsigned int button)
{
	return std::string(magic_enum::enum_name(static_cast<XboxButton>(button)));
}

std::string InputManager::JoystickToString(sf::Joystick::Axis axis) {
	return std::string(magic_enum::enum_name(axis));
}

void InputManager::ClearKeysThisFrame() {
	keysPressed.clear();
}