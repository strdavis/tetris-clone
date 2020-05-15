/*
* MIT License
*
* Copyright (c) 2020 Spencer Davis
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


#include "sdl-initializer.h"

#include <iostream>
using std::cout;
using std::endl;

#include "SDL_gpu.h"


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

