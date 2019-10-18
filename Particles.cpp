
#include "Particles.h"
#include <stdlib.h>

namespace ParticleFire {
    // Through the pixels, particle selected.
    Particles::Particles() {
        m_x = (1.6 * rand()/RAND_MAX) - 1;
        m_y = (1.6 * rand()/RAND_MAX) - 1;

        m_xspeed = 0.005 * (((2.0 * rand()) / RAND_MAX) - 1);
        m_yspeed = 0.005 * (((2.0 * rand()) / RAND_MAX) - 1);

    }

    Particles::~Particles() {

    }

    void Particles::update() {
        m_x += m_xspeed;
        m_y += m_yspeed;

        if (m_x <= -1.0 || m_x >= 1.0) {
            m_xspeed = -m_xspeed;
        }
        if (m_y <= -1.0 || m_y >= 1.0) {
            m_yspeed = -m_yspeed;
        }
    }
}
