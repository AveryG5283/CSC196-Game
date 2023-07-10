#pragma once
#include <iostream>

namespace minimum
{
	void seedRandom(unsigned int seed) { srand(seed); } //unsigned = no negative
	int random() { return rand(); }
	int random(unsigned int max) { return rand() % max; } //return 0 - (max - 1)
	int random(unsigned int min, unsigned int max) { return min + random((max - min) + 1); } //returns between min & max (inclusive)

	float randomf() { return random() / (float)RAND_MAX; }
	float randomf(float max) { return randomf() * max; }
	float randomf(float min, float max) { return min + randomf() * (max - min); }
}