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


#pragma once

#include <memory>
#include <vector>

#include "SDL2/SDL_rect.h"

class GPU_Target;
class GPU_Image;
class GameElement;
class Sprite;


// Draws a provided vector of sprites to the window.
// Renderer draws images *centered* at a given position.
// For the renderer, the origin is at the upper-left corner of the window.
class RenderingUnit
{
public:
    RenderingUnit(GPU_Target *window);

    void drawSprites(std::vector <std::shared_ptr <Sprite>> sprites);
    void setWindowCentre();
    
private:
    void drawElement(std::shared_ptr <GameElement> element);
    void blit(GPU_Image *rawImage, GPU_Target *window, SDL_Point pos);
    SDL_Point calculateAbsPos(SDL_Point posRelOrigin);
    
    GPU_Target *window;
    SDL_Point windowCentre;
};
