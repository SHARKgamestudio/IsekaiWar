#include "Animation.h"

Animation::Animation(std::string name, int start, int end, int speed, bool loop)
{
	this->name = name;
	this->start = start; this->end = end;
	this->speed = speed;
	this->loop = loop;
}