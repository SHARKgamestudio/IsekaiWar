#include "Maths.h"

#pragma region External Dependencies

#include <corecrt_math.h>

#pragma endregion

float Maths::Round(float value, int decimals) {
	float animatedValue = pow(10, decimals);
	return roundf(value * animatedValue) / animatedValue;
}

float Maths::Clamp(float value, float min, float max) {
	return value < min ? min : value > max ? max : value;
}

float Maths::Lerp(float a, float b, float t) {
	return a + (b - a) * t;
}

float Maths::Equals(float a, float b, float epsilon) {
	return (a < b + epsilon && a > b - epsilon);
}