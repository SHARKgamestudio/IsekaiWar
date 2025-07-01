#include "IntervalClock.h"

IntervalClock::IntervalClock(float maxTime) {
	this->maxTime = maxTime;
	elapseTime = 0;
}
float IntervalClock::GetTime() {
	return elapseTime;
}

float IntervalClock::GetTimeInverse() {
	return maxTime - elapseTime;
}

bool IntervalClock::UpdateLogic(float deltaTime, bool mustRestart) {
	

	if (elapseTime > maxTime) {
		if (mustRestart) {
			elapseTime = 0;
		}
		return true;
	}
	else {
		elapseTime += deltaTime;
	}
	return false;
}

void IntervalClock::Restart() {
	elapseTime = 0;
}