/*
* MIT License
*
* Copyright (c) 2020 Spencer Davis
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


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
