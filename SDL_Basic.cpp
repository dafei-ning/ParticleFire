#include <iostream>
#include <SDL.h>

using namespace std;

int main() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Partical Fire Explosion",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            )

    cout << "SDL Init succeeded..." << endl;
    SDL_Quit();
}