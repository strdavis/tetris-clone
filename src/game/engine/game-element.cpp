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


#include "game-element.h"

#include <iostream>

#include "data-transfer-types.h"
#include "image-bank.h"
#include "sprite.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


GameElement::GameElement(shared_ptr <ImageBank> imageBank, int x, int y)
    : imageBank(imageBank), pos({x, y}), width(0), height(0)
{

}


GameElement::GameElement()
{
    
}


void GameElement::update()
{
    
}


void GameElement::update(InputData inputData)
{
    
}


vector <shared_ptr <Sprite>> GameElement::getSprites()
{
    vector <shared_ptr <Sprite>> spritesNewCoordinates;
    
    for (auto sprite : sprites)
    {
        SDL_Point posRelOrigin = calcuatePosRelOrigin(sprite->getPos());
            
        spritesNewCoordinates.push_back
        (
            make_shared <Sprite> (sprite->getImage(),
                                  posRelOrigin.x,
                                  posRelOrigin.y,
                                  sprite->getWidth(),
                                  sprite->getHeight())
        );
    }
    
    return spritesNewCoordinates;
}


SDL_Point GameElement::calcuatePosRelOrigin(SDL_Point posRelElement)
{
    // Convert element-relative coordinates to origin-relative coordinates.
    SDL_Point posRelOrigin = this->getPos();
        
    posRelOrigin.x += posRelElement.x;
    posRelOrigin.y += posRelElement.y;
    
    return posRelOrigin;
}


void GameElement::setPos(SDL_Point newPos)
{
    pos = newPos;
}


SDL_Point GameElement::getPos()
{
    return pos;
}

