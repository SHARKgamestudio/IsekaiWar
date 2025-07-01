#pragma once

class Clock {
private:
	enum State {
		Stopped,
		Running,
		Paused
	};

	State current;
	float time;
public:
	Clock(bool start = false);
	void UpdateLogic(float deltaTime);

	float GetTime();
	State GetState();

	void Start();
	void Stop();

	void Pause();
	void Resume();

	void Reset();
};