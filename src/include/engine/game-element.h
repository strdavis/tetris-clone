#pragma once

#include <memory>
#include <vector>

#include "SDL_rect.h"

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
