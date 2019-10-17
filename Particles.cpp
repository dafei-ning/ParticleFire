
#include "Particles.h"
#include <stdlib.h>

namespace ParticleFire {
    Particles::Particles() {
        m_x = (1.6 * rand()/RAND_MAX) - 1;
        m_y = (1.6 * rand()/RAND_MAX) - 1;

    }

    Particles::~Particles() {

    }
}
