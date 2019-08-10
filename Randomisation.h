
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <inttypes.h>
#include "Enumerations.h"

namespace randomisation 
{

uint64_t _seed = 1;

void SetSeed(uint64_t seed) {
    _seed = seed;
}

template <RandomisationMode rMode>
uint64_t GenerateRandomUint64() {
    _seed = _seed * 48271 % 2147483647;
    return _seed;
}

template <>
uint64_t GenerateRandomUint64<RandomisationMode::SORTED>() {
    _seed += 1;
    return _seed;
}

template <>
uint64_t GenerateRandomUint64<RandomisationMode::INVERSE_SORTED>() {
    _seed -= 1;
    return _seed;
}

} // namespace randomisation

#endif // RANDOMISATION_H