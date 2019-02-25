
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdexcept>

#include "Sortable.generated.h"

namespace randomisation {

uint64_t _seed = 1;

void SetSeed(uint64_t seed) {
    _seed = seed;
}

uint64_t GenerateRandomUint64() {
    _seed = _seed * 48271 % 2147483647;
    return _seed;
}

}

#endif