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


#include "window-controller.h"

#include <iostream>

#include <SDL2_gpu/SDL_gpu.h>

#include "sdl-initializer.h"

using std::shared_ptr;
using std::make_shared;


WindowController::WindowController()
    : widthWindowed(980),
      heightWindowed(704),
      virtualWidthWindowed(245),
      virtualHeightWindowed(176),
      sdlInitializer(make_shared <SdlInitializer> ())
{
    window = sdlInitializer->createSdlGpuWindow(widthWindowed,
                                                heightWindowed,
                                                virtualWidthWindowed,
                                                virtualHeightWindowed);
    
    setWindowTitle("Engine");
    
    setVirtualFullscreenDimensions();
}


void WindowController::setVirtualFullscreenDimensions()
{
    // Get display ratio
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    
    // Cast required to do floating-point division instead of int division.
    float screenDisplayRatio = static_cast <float> (displayMode.w) / displayMode.h;
    
    virtualHeightFullscreen = virtualHeightWindowed;
    virtualWidthFullscreen = virtualHeightWindowed * screenDisplayRatio;
}


void WindowController::setWindowTitle(const char *title)
{
    SDL_Window *windowPtr = SDL_GetWindowFromID(window->context->windowID);
    SDL_SetWindowTitle(windowPtr, title);
}


void WindowController::setFullscreen(bool fullscreen)
{
    GPU_SetFullscreen(fullscreen, true);
    
    if (fullscreen)
    {
        GPU_SetVirtualResolution(window, virtualWidthFullscreen, virtualHeightFullscreen);
    }
    else
    {
        GPU_SetVirtualResolution(window, virtualWidthWindowed, virtualHeightWindowed);
    }
}


GPU_Target* WindowController::getWindow()
{
    return window;
}
