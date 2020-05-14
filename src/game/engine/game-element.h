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

#include <SDL2/SDL_rect.h>

struct ImageBank;
struct InputData;

class Sprite;


// An object in the game domain.
// Can be triggered to update.
// Can be queried for a vector of sprites.
//
// Coordinates for game elements are relative to the centre of the window.
class GameElement
{
public:
    GameElement(std::shared_ptr <ImageBank> imageBank, int x = 0, int y = 0);
    GameElement();

    virtual void update();
    virtual void update(InputData inputData);
    virtual std::vector <std::shared_ptr <Sprite>> getSprites();
    
    void setPos(SDL_Point newPos);
    SDL_Point getPos();
    
protected:
    SDL_Point calcuateGlobalSpriteCoordinates(SDL_Point posRelElement);
    
    SDL_Point pos;
    int width;
    int height;
    std::shared_ptr <ImageBank> imageBank;
    std::vector <std::shared_ptr <Sprite>> sprites;
};
