#include "rendering-unit.h"

#include <iostream>

#include "SDL.h"
#include "SDL_gpu.h"

#include "game-element.h"
#include "sprite.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


RenderingUnit::RenderingUnit(GPU_Target *window)
    : window(window)

{    
    setWindowCentre();
}


void RenderingUnit::drawSprites(vector <shared_ptr <Sprite>> sprites)
{
    GPU_Clear(window);
    
    // Copy all sprites to the frame buffer
    for (auto sprite : sprites)
    {
        // Many sprites can share the same image, but have different sizes,
        // so the virtual resolution must be set for each sprite before it is drawn.
        GPU_SetImageVirtualResolution(sprite->getRawImage(),
                                      sprite->getWidth(),
                                      sprite->getHeight());
        
        // Convert origin-relative coordinates of each sprite to absolute coordinates.
        SDL_Point absPos = calculateAbsPos(sprite->getPos());
        
        blit(sprite->getRawImage(), window, absPos);
    }
    
    // Swap current rendered frame with frame buffer contents
    GPU_Flip(window);
}


SDL_Point RenderingUnit::calculateAbsPos(SDL_Point posRelOrigin)
{
    SDL_Point absPos = windowCentre;
        
    absPos.x += posRelOrigin.x;
    absPos.y -= posRelOrigin.y;
    
    return absPos;
}


void RenderingUnit::blit(GPU_Image *rawImage, GPU_Target *window, SDL_Point pos)
{
    // Remember that GPU_Blit() draws the image *centered* at the given position
    GPU_Blit(rawImage, NULL, window, (float)pos.x, (float)pos.y);
}


void RenderingUnit::setWindowCentre()
{
    Uint16 width;
    Uint16 height;
    
    GPU_GetVirtualResolution(window, &width, &height);
    windowCentre = {(width / 2), (height / 2)};
}
