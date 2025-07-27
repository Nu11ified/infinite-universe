#ifndef UNIGEN
#define UNIGEN

#include "fast_rand.hpp"
#include "model.hpp"
#include <cstdint>

namespace UGEN {

GameModel::StarSystem GenerateStar(uint32_t x, uint32_t y,
                                    Jrand::FastRand &rnd);  
} // namespace UGEN

#endif // UNIGEN