#include <iostream>
#include <iomanip>
#include <math.h>
#include <SDL.h>

#include "Screen.h"

using namespace std;
using namespace ParticleFire;

int main() {

    Screen screen;

    if (screen.init() == false) {
        cout << "Error initiating SDL." << endl;
    }

    // create particle, update, check.
    while(true) {
        // counting the seconds it takes to drive the change through sin().
        // The sin(time_elapsed) ranges from -1 to 1.
        int time_elapsed = SDL_GetTicks();
        // The color index ranges from 0 to 255, make the color reside in this range.
        double color_change = (1 + sin(time_elapsed * 0.001)) * 128;
        for (int j = 0; j < Screen::SCREEN_HEIGHT; j++) {
            for (int i = 0; i < Screen::SCREEN_WIDTH; i++) {
                screen.setPixel(i, j, color_change, 0, 0);
            }
        }
        screen.update();
        if(screen.processEvent() == false) {
            break;
        }
    }

    screen.finish();


}