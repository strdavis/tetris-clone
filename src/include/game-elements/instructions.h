#pragma once

#include <memory>

#include "game-element.h"


// Text banner containing information
// about game controls.
class Instructions : public GameElement
{
public:
    Instructions(std::shared_ptr <ImageBank> imageBank);
    
private:
    std::shared_ptr <Sprite> instructionsImage;
};
