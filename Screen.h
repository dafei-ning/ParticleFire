
#ifndef SDL_BASIC_SCREEN_H
#define SDL_BASIC_SCREEN_H

#include <iostream>
#include <SDL.h>


namespace ParticleFire {
    class Screen {
    public:
        const static int SCREEN_WIDTH = 1024;
        const static int SCREEN_HEIGHT = 800;
    private:
        // Conventionally make variable noted as member
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;

    public:
        Screen();
        bool init();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        void update();
        bool processEvent();
        void clear();
        void finish();
        void boxBlur();
    private:
        bool withinEdge(int i, int j);
    };
}


#endif //SDL_BASIC_SCREEN_H
