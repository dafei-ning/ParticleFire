
#ifndef SDL_BASIC_SWARM_H
#define SDL_BASIC_SWARM_H

#include "Particles.h"

namespace ParticleFire {
    class Swarm {
    public:
        const static int PARTICLES_NUMBER = 16000;
    private:
        Particles *m_pParticles;
        int lastTime;
    public:
        Swarm();
        virtual ~Swarm();

        const Particles * const getParticles() { return m_pParticles; };
        void update(int time);


    };
}



#endif //SDL_BASIC_SWARM_H
