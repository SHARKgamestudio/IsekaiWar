#pragma once
#include <string>

struct Animation {
	std::string name;
	int start, end;
	int speed;
	bool loop;

	Animation(std::string name, int start, int end, int speed = 1, bool loop = true);
};