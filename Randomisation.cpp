
#include "Randomisation.h"

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