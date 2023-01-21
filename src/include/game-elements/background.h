#pragma once

#include <memory>

#include "game-element.h"


// Contains images for game backdrop.
class Background : public GameElement
{
public:
    Background(std::shared_ptr <ImageBank> imageBank);

private:
    std::shared_ptr <Sprite> firstLayer;
};

