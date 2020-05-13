#pragma once

#include <memory>

#include "panel.h"

class DigitalDisplay;


class HighScoreDisplay : public Panel
{
public:
    HighScoreDisplay(std::shared_ptr <ImageBank> imageBank);
    
    std::vector <std::shared_ptr <Sprite>> getSprites() override;
        
    void update(int newHighScore);
        
private:
    std::shared_ptr <DigitalDisplay> digitalDisplay;
        
};
