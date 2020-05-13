#pragma once

#include <random>


class RandomNumberGenerator
{
public:
    RandomNumberGenerator();
    
    int getRandomIntInRange(int min, int max);
    
private:
    std::random_device randomSeed;
    std::mt19937 randomGenerator;
};
