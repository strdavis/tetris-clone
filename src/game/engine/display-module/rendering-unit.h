#pragma once

#include <memory>
#include <vector>

#include <SDL2/SDL_rect.h>

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
