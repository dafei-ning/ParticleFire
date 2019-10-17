#include <iostream>
#include <iomanip>
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

        for (int j = 0; j < Screen::SCREEN_HEIGHT; j++) {
            for (int i = 0; i < Screen::SCREEN_WIDTH; i++) {
                screen.setPixel(i, j, 128, 0, 255);
            }
        }
        //screen.setPixel(512, 400, 255, 255, 255);
        screen.update();
        if(screen.processEvent() == false) {
            break;
        }
    }

    screen.finish();


}