#ifndef FASTRAND
#define FASTRAND

#include <cstdint>

namespace Jrand {

struct FastRand {

    uint64_t seed;
    uint32_t rnd();
    int randInteger(int min, int max);
    double rndDouble(double min, double max);
    
};

}

#endif // FASTRAND