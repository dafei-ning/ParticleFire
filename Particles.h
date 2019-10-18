
#ifndef SDL_BASIC_PARTICLES_H
#define SDL_BASIC_PARTICLES_H

#include <iostream>

namespace ParticleFire {
    struct Particles {
    public:
        double m_x;
        double m_y;


    public:
        Particles();
        ~Particles();
        void update();

    };
}




#endif //SDL_BASIC_PARTICLES_H
