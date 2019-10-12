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
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
            );

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    bool event_running = true;

    SDL_Event event;

    // create particle, update, check.
    while(event_running) {
        // Fetch the event to check if should quit.
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                event_running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}