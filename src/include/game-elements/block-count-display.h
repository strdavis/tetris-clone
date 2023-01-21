#pragma once

#include <memory>
#include <array>

#include "panel.h"

class DigitalDisplay;


// Contains several digital displays,
// showing how many of each type of block have fallen.
class BlockCountDisplay : public Panel
{
public:
    BlockCountDisplay(std::shared_ptr <ImageBank> imageBank);
    
    std::vector <std::shared_ptr <Sprite>> getSprites() override;
    
    void update(std::array <int, 7> blockCounts);
    
private:
    std::shared_ptr <Sprite> oBlockSprite;
    std::shared_ptr <Sprite> lBlockSprite;
    std::shared_ptr <Sprite> jBlockSprite;
    std::shared_ptr <Sprite> zBlockSprite;
    std::shared_ptr <Sprite> sBlockSprite;
    std::shared_ptr <Sprite> tBlockSprite;
    std::shared_ptr <Sprite> iBlockSprite;
    std::shared_ptr <DigitalDisplay> oBlocksDigitalDisplay;
    std::shared_ptr <DigitalDisplay> lBlocksDigitalDisplay;
    std::shared_ptr <DigitalDisplay> jBlocksDigitalDisplay;
    std::shared_ptr <DigitalDisplay> zBlocksDigitalDisplay;
    std::shared_ptr <DigitalDisplay> sBlocksDigitalDisplay;
    std::shared_ptr <DigitalDisplay> tBlocksDigitalDisplay;
    std::shared_ptr <DigitalDisplay> iBlocksDigitalDisplay;
    std::vector <std::shared_ptr <DigitalDisplay>> digitalDisplays;
    
};
