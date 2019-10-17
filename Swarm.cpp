
#include "Swarm.h"

namespace ParticleFire {
    Swarm::Swarm() {
        m_pParticles = new Particles[PARTICLES_NUMBER];

    }

    Swarm::~Swarm() {
        delete [] m_pParticles;

    }

    void Swarm::update() {
        for (int i = 0; i < Swarm::PARTICLES_NUMBER; i++) {
            m_pParticles[i].update();
        }
    }
}
