#pragma once

class IntervalClock {
private:
    float elapseTime;

public:
    float maxTime;

    IntervalClock(float maxTime);

    float GetTime();
    float GetTimeInverse();

    bool UpdateLogic(float deltaTime, bool mustRestart = true);
    void Restart();
};