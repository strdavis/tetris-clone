#pragma once

#include <memory>

#include "panel.h"

class DigitalDisplay;


class ScoreDisplay : public Panel
{
public:
    ScoreDisplay(std::shared_ptr <ImageBank> imageBank);
    
    std::vector <std::shared_ptr <Sprite>> getSprites() override;
    
    void update(int newScore);
    
private:
    std::shared_ptr <DigitalDisplay> digitalDisplay;
    
};
