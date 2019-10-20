
#include "Swarm.h"

namespace ParticleFire {
    Swarm::Swarm(): lastTime(0) {
        m_pParticles = new Particles[PARTICLES_NUMBER];

    }

    Swarm::~Swarm() {
        delete [] m_pParticles;

    }

    void Swarm::update(int time) {
        int interval = time - lastTime;
        for (int i = 0; i < Swarm::PARTICLES_NUMBER; i++) {
            m_pParticles[i].update(interval);
        }
        lastTime = time;
    }
}
