#include "next-block-display.h"

#include "image-bank.h"
#include "sprite.h"

using std::shared_ptr;
using std::make_shared;


NextBlockDisplay::NextBlockDisplay(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),
      nextBlockIntCode(0),
      nextBlockSprite(make_shared <Sprite> ())
{
    sprites.push_back(nextBlockSprite);
    
    pos = {65, 64};
    
    background->setImage(imageBank->white);
    background->setSize(32, 32);
    
    frame->setImage(imageBank->nextBlockFrame);
    frame->setSize(48, 48);
    
    nextBlockSprite->setImage(imageBank->iBlock); // Default image.
    nextBlockSprite->setPos(0, -4);
    nextBlockSprite->setSize(24, 16);
}


void NextBlockDisplay::update(int newNextBlockIntCode)
{
    if (nextBlockIntCode != newNextBlockIntCode)
    {
        setBlock(newNextBlockIntCode);
    }
}


void NextBlockDisplay::setBlock(int newNextBlockIntCode)
{
    nextBlockIntCode = newNextBlockIntCode;
    
    shared_ptr <WrappedGpuImage> blockImage;
    int w = 24;
    int h = 16;
    
    switch (newNextBlockIntCode)
    {
        // I-block and O-block images must have different dimensions to fit in the display;
        case 0:
            blockImage = imageBank->iBlock;
            w = 32;
            break;
            
        case 1:
            blockImage = imageBank->oBlock;
            w = 16;
            break;
            
        case 2:
            blockImage = imageBank->tBlock;
            break;
            
        case 3:
            blockImage = imageBank->jBlock;
            break;
            
        case 4:
            blockImage = imageBank->lBlock;
            break;
            
        case 5:
            blockImage = imageBank->zBlock;
            break;
            
        case 6:
            blockImage = imageBank->sBlock;
            break;
    }
    
    nextBlockSprite->setImage(blockImage);
    nextBlockSprite->setSize(w, h);
    
    
}
