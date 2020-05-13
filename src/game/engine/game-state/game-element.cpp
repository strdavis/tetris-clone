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

