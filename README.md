# ParticleFire

A 1024 * 800 window simulating fire work, practicing SDL and C++.

## CMakeList

MacOS is different from Linux system and should avoid unexpected mistakes.

Using 'find' instead of using 'set'.

'''
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(SDL_Basic main.cpp)
target_link_libraries(SDL_Basic ${SDL2_LIBRARIES})
'''