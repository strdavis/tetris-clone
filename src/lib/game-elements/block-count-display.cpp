#include "block-count-display.h"

#include <iostream>

#include "data-transfer-types.h"
#include "image-bank.h"
#include "sprite.h"
#include "digital-display.h"

using std::array;
using std::vector;
using std::shared_ptr;
using std::make_shared;


BlockCountDisplay::BlockCountDisplay(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),

      // Block sprites
      oBlockSprite(make_shared <Sprite> (imageBank->oBlock, -6, 49, 16, 16)),
      lBlockSprite(make_shared <Sprite> (imageBank->lBlock, -10, 31, 24, 16)),
      jBlockSprite(make_shared <Sprite> (imageBank->jBlock, -10, 13, 24, 16)),
      zBlockSprite(make_shared <Sprite> (imageBank->zBlock, -10, -5, 24, 16)),
      sBlockSprite(make_shared <Sprite> (imageBank->sBlock, -10, -23, 24, 16)),
      tBlockSprite(make_shared <Sprite> (imageBank->tBlock, -10, -41, 24, 16)),
      iBlockSprite(make_shared <Sprite> (imageBank->iBlock, -14, -59, 32, 16)),

      // Digital displays
      oBlocksDigitalDisplay(make_shared <DigitalDisplay> (imageBank, 34, 53)),
      lBlocksDigitalDisplay(make_shared <DigitalDisplay> (imageBank, 34, 35)),
      jBlocksDigitalDisplay(make_shared <DigitalDisplay> (imageBank, 34, 17)),
      zBlocksDigitalDisplay(make_shared <DigitalDisplay> (imageBank, 34, -1)),
      sBlocksDigitalDisplay(make_shared <DigitalDisplay> (imageBank, 34, -19)),
      tBlocksDigitalDisplay(make_shared <DigitalDisplay> (imageBank, 34, -37)),
      iBlocksDigitalDisplay(make_shared <DigitalDisplay> (imageBank, 34, -55))
{
    pos = {-83, -13};
    
    background->setSize(67, 134);
    
    frame->setImage(imageBank->statsFrame);
    frame->setSize(75, 142);
    
    digitalDisplays.push_back(iBlocksDigitalDisplay);
    digitalDisplays.push_back(oBlocksDigitalDisplay);
    digitalDisplays.push_back(tBlocksDigitalDisplay);
    digitalDisplays.push_back(jBlocksDigitalDisplay);
    digitalDisplays.push_back(lBlocksDigitalDisplay);
    digitalDisplays.push_back(zBlocksDigitalDisplay);
    digitalDisplays.push_back(sBlocksDigitalDisplay);
}


void BlockCountDisplay::update(array <int, 7> blockCounts)
{
    for (int i = 0; i < 7; i++)
    {
        if ((digitalDisplays[i])->getDisplayValue() != blockCounts[i])
        {
            (digitalDisplays[i])->setDisplay(blockCounts[i]);
        }
    }
}


vector <shared_ptr <Sprite>> BlockCountDisplay::getSprites()
{
    // Clear sprites vector.
    vector <shared_ptr <Sprite>> temp;
    sprites.swap(temp);
    
    sprites.push_back(background);
    sprites.push_back(frame);
    
    sprites.push_back(oBlockSprite);
    sprites.push_back(lBlockSprite);
    sprites.push_back(jBlockSprite);
    sprites.push_back(zBlockSprite);
    sprites.push_back(sBlockSprite);
    sprites.push_back(tBlockSprite);
    sprites.push_back(iBlockSprite);
    
    for (auto display : digitalDisplays)
    {
        vector <shared_ptr <Sprite>> displaySprites = display->getSprites();
        sprites.insert(end(sprites), begin(displaySprites), end(displaySprites));
    }
    
    return GameElement::getSprites();
}
