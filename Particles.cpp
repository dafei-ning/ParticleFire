
#include "Particles.h"
#include <math.h>
#include <stdlib.h>

namespace ParticleFire {
    // Through the pixels, particle selected.
    Particles::Particles(): m_x(0), m_y(0) {
        init();
    }

    Particles::~Particles() {

    }

    void Particles::init() {
        m_x = 0;
        m_y = 0;
        m_direction = (2 * M_PI * rand()) / RAND_MAX;
        m_speed = (0.08 * rand()) / RAND_MAX;

        m_speed = m_speed * m_speed;
    }

    void Particles::update(int interval) {
        // 只是象征性地统一了一下时间
        m_direction += interval * 0.0002;
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * sin(m_direction);
        m_x += xspeed * interval;
        m_y += yspeed * interval;
        if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
            init();
        }
        if (rand() < RAND_MAX/100) {
            int();
        }
    }
}
