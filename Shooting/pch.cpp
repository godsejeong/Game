#include "pch.h"

float random(float from, float to) {

	static mt19937 generator;
	static uniform_real_distribution<float> distribution(from, to);
	return distribution(generator);
}