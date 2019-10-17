
#include "Swarm.h"

namespace ParticleFire {
    Swarm::Swarm() {
        m_pParticles = new Particles[PARTICLES_NUMBER];

    }

    Swarm::~Swarm() {
        delete [] m_pParticles;

    }
}
