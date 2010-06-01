/**
    Palm disclaimer
**/
#include <stdio.h>
#include <math.h>


#include <GLES2/gl2.h>
#include "SDL.h"

SDL_Surface *Surface;               // Screen surface to retrieve width/height information


int main(int argc, char** argv)
{
    // Initialize the SDL library with the Video subsystem
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);

    // Tell it to use OpenGL version 2.0
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);

    // Set the video mode to full screen with OpenGL-ES support
    Surface = SDL_SetVideoMode(320, 480, 0, SDL_OPENGL);

    // Event descriptor
    SDL_Event Event;

    do {
        // Process the events
        while (SDL_PollEvent(&Event)) {
            switch (Event.type) {
                // List of keys that have been pressed
                case SDL_KEYDOWN:
                    switch (Event.key.keysym.sym) {
                        // Escape forces us to quit the app
                        case SDLK_ESCAPE:
                            Event.type = SDL_QUIT;
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }

    } while (Event.type != SDL_QUIT);
    // We exit anytime we get a request to quit the app

    // Cleanup
    SDL_Quit();

    return 0;
}
