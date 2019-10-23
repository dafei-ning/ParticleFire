
#ifndef SDL_BASIC_PARTICLES_H
#define SDL_BASIC_PARTICLES_H

#include <iostream>
#include "Screen.h"

namespace ParticleFire {
    struct Particles {
        double m_x;
        double m_y;
        double m_speed;
        double m_direction;
    public:
        Particles();
        ~Particles();
        void update(int interval);
    };
}

#endif //SDL_BASIC_PARTICLES_H
