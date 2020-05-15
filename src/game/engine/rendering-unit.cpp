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


#include "rendering-unit.h"

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2_gpu/SDL_gpu.h"

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
    GPU_Blit(rawImage, NULL, window, pos.x, pos.y);
}


void RenderingUnit::setWindowCentre()
{
    Uint16 width;
    Uint16 height;
    
    GPU_GetVirtualResolution(window, &width, &height);
    windowCentre = {(width / 2), (height / 2)};
}
