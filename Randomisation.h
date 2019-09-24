
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <inttypes.h>
#include "Enumerations.h"

namespace randomisation 
{

void SetSeed(uint64_t seed);

template <RandomisationMode rMode>
uint64_t GenerateRandomUint64();

template <>
uint64_t GenerateRandomUint64<RandomisationMode::DEFAULT>();

template <>
uint64_t GenerateRandomUint64<RandomisationMode::SORTED>();

template <>
uint64_t GenerateRandomUint64<RandomisationMode::INVERSE_SORTED>();

} // namespace randomisation

#endif // RANDOMISATION_H