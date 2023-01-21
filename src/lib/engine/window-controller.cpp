#include "window-controller.h"

#include <iostream>

#include "SDL_gpu.h"

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
    
    setWindowTitle("Tetris");
    
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
    virtualWidthFullscreen = (int) ((double)virtualHeightWindowed * screenDisplayRatio);
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
