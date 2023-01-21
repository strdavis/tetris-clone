#pragma once

#include <memory>

#include "game-element.h"


// A title banner.
class Title : public GameElement
{
public:
    Title(std::shared_ptr <ImageBank> imageBank);
    
private:
    std::shared_ptr <Sprite> titleImage;
};
