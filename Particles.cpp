
#include "Particles.h"
#include <math.h>
#include <stdlib.h>

namespace ParticleFire {
    // Through the pixels, particle selected.
    Particles::Particles(): m_x(0), m_y(0) {

        m_direction = (2 * M_PI * rand()) / RAND_MAX;
        m_speed = (0.0003 * rand()) / RAND_MAX;

    }

    Particles::~Particles() {

    }

    void Particles::update(int interval) {
        // 只是象征性地统一了一下时间
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);
        m_x += xspeed * interval;
        m_y += yspeed * interval;
    }
}
