#include <iostream>
#include <SDL.h>

using namespace std;

int main() {

    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 800;

    // Protection against failure of the lib.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Partical Fire Explosion",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    // When the screen refreshing, don't render the window.
    // index of the rendering driver to be -1.
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
                                             SCREEN_WIDTH, SCREEN_HEIGHT);

    bool event_running = true;

    SDL_Event event;

    // create particle, update, check.
    while(event_running) {
        // Fetch the event to check status.
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                event_running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}