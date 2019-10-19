
#include "Particles.h"
#include <math.h>
#include <stdlib.h>

namespace ParticleFire {
    // Through the pixels, particle selected.
    Particles::Particles(): m_x(0), m_y(0) {

        m_direction = (2 * M_PI * rand()) / RAND_MAX;
        m_speed = (0.0001 * rand()) / RAND_MAX;

    }

    Particles::~Particles() {

    }

    void Particles::update() {
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);

        m_x += xspeed;
        m_y += yspeed;

    }
}
