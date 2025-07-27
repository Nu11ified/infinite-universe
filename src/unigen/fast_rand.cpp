#include "fast_rand.hpp"

uint32_t Jrand::FastRand::rnd() {
    seed += 0xe120fc15;
    uint64_t tmp; 
    tmp = (uint64_t)seed * 0x4a39b70d;
    uint32_t m1 = (tmp >> 32) ^ tmp;
    tmp = (uint64_t)m1 * 0x12fad5c9;
    uint32_t m2 = (tmp >> 32) ^ tmp;
    return m2;
}

int Jrand::FastRand::randInteger(int min, int max) {
    return (rnd() % (max - min)) + min;

}

double Jrand::FastRand::rndDouble(double min, double max) {
    return ((double)rnd() / (double)UINT32_MAX) * (max - min) + min;
}