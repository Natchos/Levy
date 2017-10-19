#pragma once
#include <cstdlib>
#include <ctime>

class Randomizer
{
public:
	Randomizer()
	{srand(time(0));};

	float fGenerateRandom(float min, float max)
	{
		return min + (float)rand()/((float)RAND_MAX/(max-min));
	}

	int iGenerateRandom(int min, int max)
	{
		return (int)rand()%(max-min+1)+min;
	}

	float fmGenerateRandom(float max)
	{
		return (float)rand()/((float)RAND_MAX/max);
	}

	int imGenerateRandom(int max)
	{
		return (int)rand()%(max+1);
	}
};
