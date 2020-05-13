#pragma once

#include <memory>

#include "panel.h"


class LevelDisplay : public Panel
{
public:
    LevelDisplay(std::shared_ptr <ImageBank> imageBank);
    
    void update(int level);
    void setLevelSprite(int level);
    
private:
    
    int levelDisplayed;
    std::shared_ptr <Sprite> levelSprite;

};
