#pragma once

#include <memory>

#include "game-element.h"

class WrappedGpuImage;


// Element for visual oraganization -- a frame with a background image.
class Panel : public GameElement
{
public:
    Panel(std::shared_ptr <ImageBank> imageBank);
    
protected:
    std::shared_ptr <Sprite> background;
    std::shared_ptr <Sprite> frame;
};
