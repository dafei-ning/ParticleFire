
#include "Screen.h"

namespace ParticleFire {
    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

    }

    bool Screen::init() {
        // Protection against failure of the lib.
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }
        m_window = SDL_CreateWindow("Partical Fire Explosion",
                                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (m_window == NULL) {
            SDL_Quit();
            return false;
        }
        // When the screen refreshing, don't render the window.
        // index of the rendering driver to be -1.
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
                                                 SCREEN_WIDTH, SCREEN_HEIGHT);
        if (m_renderer == NULL) {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        if (m_texture == NULL) {
            SDL_DestroyWindow(m_window);
            SDL_DestroyRenderer(m_renderer);
            SDL_Quit();
            return false;
        }
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        // Change each pixel.
        // White:  0xFFFFFFFF
        // Red:    0xFF0000FF
        // Green:  0x00FF00FF
        // Blue:   0x0000FFFF
        // Purple: 0xFF00FFFF
        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            m_buffer[i] = 0x00000000;
        }
        return true;
    }

    void Screen::clear() {
        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
        // Protection through particle size
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return;
        }
        Uint32 color = 0;
        color += red;   // 0000ff12 Red
        color <<= 8;
        color += green; // 00ff1234 green
        color <<= 8;
        color += blue;  // ff123456 blue
        color <<= 8;
        color += 0xFF;
        // For every pixel, the buffer will change by given color.
        m_buffer[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::update() {
        // Update the screen.
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }

    bool Screen::processEvent() {
        SDL_Event event;
        // Fetch the event to check status.
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;
            }
        }
        return true;
    }

    void Screen::finish() {
        // Clean up before finish.
        delete [] m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();

    }
}
