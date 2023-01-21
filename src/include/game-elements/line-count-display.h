#pragma once

#include <memory>

#include "panel.h"

class DigitalDisplay;


class LineCountDisplay : public Panel
{
public:
    LineCountDisplay(std::shared_ptr <ImageBank> imageBank);
    
    std::vector <std::shared_ptr <Sprite>> getSprites() override;
        
    void update(int newLineCount);
        
private:
    std::shared_ptr <DigitalDisplay> digitalDisplay;

};
