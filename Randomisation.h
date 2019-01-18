
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdexcept>
#include <random>

#include "Sortable.generated.h"

namespace randomisation {

std::minstd_rand generator;
std::uniform_int_distribution<unsigned long long> distribution(0); //default top limit at numeric_limit<unsigned long long>()

void SetSeed(unsigned long seed) {
    generator.seed(seed);
}

uint64_t GenerateRandomUint64() {
    return (uint64_t) distribution(generator);
}

}

#endif