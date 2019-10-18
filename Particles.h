
#ifndef SDL_BASIC_PARTICLES_H
#define SDL_BASIC_PARTICLES_H

#include <iostream>

namespace ParticleFire {
    struct Particles {
        double m_x;
        double m_y;

        double m_xspeed;
        double m_yspeed;


    public:
        Particles();
        ~Particles();
        void update();

    };
}




#endif //SDL_BASIC_PARTICLES_H
