#include "random-number-generator.h"

using std::uniform_int_distribution;


RandomNumberGenerator::RandomNumberGenerator()
{
    randomGenerator.seed(randomSeed());
}


int RandomNumberGenerator::getRandomIntInRange(int min, int max)
{
    std::uniform_int_distribution <> distr(min, max);

    return distr(randomGenerator);
}
