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

    // create particle, update, check.
    while(true) {
        if(!screen.processEvent()) {
            break;
        }
    }

    screen.finish();

}