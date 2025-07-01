#pragma once

class Maths {
public:
	static float Round(float value, int decimals);
	static float Clamp(float value, float min, float max);
	static float Lerp(float a, float b, float t);
	static float Equals(float a, float b, float epsilon);
};