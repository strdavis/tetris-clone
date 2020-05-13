#pragma once

#include <memory>

#include "panel.h"


class NextBlockDisplay : public Panel
{
public:
    NextBlockDisplay(std::shared_ptr <ImageBank> imageBank);
    
    void update(int newNextBlockIntCode);
    void setBlock(int newNextBlockIntCode);
    
private:
    int nextBlockIntCode;
    std::shared_ptr <Sprite> nextBlockSprite;
};
