#include "unigen.hpp"
#include "model.hpp"

GameModel::StarSystem UGEN::GenerateStar(uint32_t x, uint32_t y, 
                                        Jrand::FastRand &rnd) {
    
    rnd.seed = Jrand::PerfectlyHasThem(x, y);

    return GameModel::StarSystem{
        rnd.rndDouble(1, 2000),
        GameModel::COLORS[rnd.randInteger(0, 6)],
        rnd.rndDouble(1, 25),
        rnd.rndDouble(1000, 210000),
        rnd.rndDouble(1, 10000)
    };
} // namespace UGEN