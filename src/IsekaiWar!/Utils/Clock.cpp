#include "Clock.h"

Clock::Clock(bool start) {
	this->current = start ? Running : Stopped;
	this->time = 0.0f;
}

void Clock::UpdateLogic(float deltaTime) {
	if (current == Running) {
		time += deltaTime;
	}
}

float Clock::GetTime() {
	return time;
}

Clock::State Clock::GetState() {
	return current;
}

void Clock::Start() {
	time = 0.0f;
	current = Running;
}

void Clock::Stop() {
	current = Stopped;
	time = 0.0f;
}

void Clock::Pause() {
	current = Paused;
}

void Clock::Resume() {
	current = Running;
}

void Clock::Reset() {
	time = 0.0f;
}