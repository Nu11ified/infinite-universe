#ifndef JMODEL 
#define JMODEL 

namespace GameModel {

enum StarColor { White, Blue, Red, Yellow, Orange, Gold };

const StarColor COLORS[6] = { White, Blue, Red, Yellow, Orange, Gold };

struct StarSystem {
    double Radius;
    StarColor Color;
    double Luminosity;
    double SurfaceTemperature;
    double Mass;
};

} // namespace GameModel

#endif // JMODEL
