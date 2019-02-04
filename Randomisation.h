
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdexcept>

#include "Sortable.generated.h"

namespace randomisation {

unsigned long _seed;

void SetSeed(unsigned long seed) {
    _seed = seed;
}

uint64_t GenerateRandomUint64() {
    _seed = _seed * 48271 % 2147483647;
    return (uint64_t) _seed;
}

}

#endif