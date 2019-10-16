#include <iostream>
#include <SDL.h>

#include "Screen.h"

using namespace std;
using namespace ParticleFire;

int main() {



    Screen screen;


    if (screen.init() == false) {
        cout << "Error initiating SDL." << endl;
    }

    bool event_running = true;
    // create particle, update, check.
    while(event_running) {
        if(!screen.processEvent()) {
            event_running = false;
        }
    }

    screen.finish();


}