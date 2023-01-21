#include "next-block-display.h"

#include "image-bank.h"
#include "sprite.h"

using std::shared_ptr;
using std::make_shared;


NextBlockDisplay::NextBlockDisplay(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),
      nextBlockIdentifier(-1),
      nextBlockSprite(make_shared <Sprite> ())
{
    sprites.push_back(nextBlockSprite);
    blockImages.push_back(imageBank->iBlock);
    blockImages.push_back(imageBank->oBlock);
    blockImages.push_back(imageBank->tBlock);
    blockImages.push_back(imageBank->jBlock);
    blockImages.push_back(imageBank->lBlock);
    blockImages.push_back(imageBank->zBlock);
    blockImages.push_back(imageBank->sBlock);
    
    pos = {65, 64};
    
    background->setImage(imageBank->white);
    background->setSize(32, 32);
    
    frame->setImage(imageBank->nextBlockFrame);
    frame->setSize(48, 48);
    
    nextBlockSprite->setImage(imageBank->iBlock); // Default image.
    nextBlockSprite->setPos(0, -4);
    nextBlockSprite->setSize(24, 16);
}


void NextBlockDisplay::update(int newNextBlockIdentifier)
{
    if (nextBlockIdentifier != newNextBlockIdentifier)
    {
        setBlock(newNextBlockIdentifier);
    }
}


void NextBlockDisplay::setBlock(int newNextBlockIdentifier)
{
    int w = 24;
    if (newNextBlockIdentifier == 0) { w = 32; }; // I-block is slightly wider.
    if (newNextBlockIdentifier == 1) { w = 16; }; // O-block is slightly narrower.
    
    int h = 16;
    
    nextBlockSprite->setImage(blockImages[newNextBlockIdentifier]);
    nextBlockSprite->setSize(w, h);
}
