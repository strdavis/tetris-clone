#pragma once

#include <memory>
#include <vector>

#include "panel.h"

class WrappedGpuImage;


class NextBlockDisplay : public Panel
{
public:
    NextBlockDisplay(std::shared_ptr <ImageBank> imageBank);
    
    void update(int newNextBlockIdentifier);
    void setBlock(int newNextBlockIdentifier);
    
private:
    int nextBlockIdentifier;
    std::shared_ptr <Sprite> nextBlockSprite;
    std::vector <std::shared_ptr <WrappedGpuImage>> blockImages;
};
