#include "sdl-initializer.h"

#include <iostream>
using std::cout;
using std::endl;

#include <SDL2_gpu/SDL_gpu.h>


SdlInitializer::SdlInitializer()
{
    GPU_SetDebugLevel(GPU_DEBUG_LEVEL_MAX);
}


GPU_Target* SdlInitializer::createSdlGpuWindow(int windowWidthWindowed,
                                               int windowHeightWindowed,
                                               int windowVirtualWidthWindowed,
                                               int windowVirtualHeightWindowed)
{
    // Create window and renderer
    GPU_Target *window = GPU_Init(windowWidthWindowed,
                                  windowHeightWindowed,
                                  SDL_WINDOW_ALLOW_HIGHDPI |
                                  SDL_WINDOW_OPENGL);
    
    if (window == NULL)
    {
        cout << "Could not create window." << endl;
    }
    
    GPU_SetVirtualResolution(window, windowVirtualWidthWindowed, windowVirtualHeightWindowed);
    
    // Relative mouse mode false -> mouse cursor is not disabled while window runs.
    SDL_SetRelativeMouseMode(SDL_FALSE);
    
    return window;
}

