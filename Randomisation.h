
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdexcept>
#include <random>

#include "Numbers.h"
#include "Sortable.generated.h"

namespace randomisation {

std::default_random_engine generator;
std::uniform_int_distribution<unsigned long long> distribution(0, UINT_64_MAX_VALUE);

void SetSeed(unsigned long seed) {
    generator.seed(seed);
}

uint64_t GenerateRandomUint64() {
    return (uint64_t) distribution(generator);
}

}

#endif