#include <iostream>
#include <SDL.h>

using namespace std;

int main() {
    
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 800;
    
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
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}
