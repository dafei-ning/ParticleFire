
#include "Particles.h"
#include <stdlib.h>

namespace ParticleFire {
    // Through the pixels, particle selected.
    Particles::Particles() {
        m_x = (1.6 * rand()/RAND_MAX) - 1;
        m_y = (1.6 * rand()/RAND_MAX) - 1;

    }

    Particles::~Particles() {

    }

    void Particles::update() {
        const double xspeed = 0.0005 * (((2.0 * rand()) / RAND_MAX) - 1);
        const double yspeed = 0.0005 * (((2.0 * rand()) / RAND_MAX) - 1);

        m_x += xspeed;
        m_y += yspeed;
    }
}
