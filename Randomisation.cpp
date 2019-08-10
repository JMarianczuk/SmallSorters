
#include "Randomisation.h"

namespace randomisation
{

uint64_t _seed = 1;

void SetSeed(uint64_t seed) {
    _seed = seed;
}

template <>
uint64_t GenerateRandomUint64<RandomisationMode::DEFAULT>() {
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

} //namespace randomisation