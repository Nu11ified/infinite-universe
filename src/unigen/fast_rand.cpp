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
    return ((double)rnd() / (double)(UINT32_MAX)) * (max - min) + min;
}

//Cantor pairing function
uint64_t Jrand::PerfectlyHasThem(uint32_t a, uint32_t b) {
    uint64_t A = (uint64_t)(a >= 0 ? 2 * (int64_t)a : -2 * (int64_t)a - 1);
    uint64_t B = (uint64_t)(b >= 0 ? 2 * (int64_t)b : -2 * (int64_t)b - 1);
    int64_t C = (int64_t)((a >= B ? A * A + A + B : A + B * B) / 2);
    return (a < 0 && b < 0) || (a >= 0 && b >= 0) ? C : -C - 1;
}