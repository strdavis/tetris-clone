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
    nextBlockIdentifier = newNextBlockIdentifier;
    
    shared_ptr <WrappedGpuImage> blockImage;
    int w = 24;
    int h = 16;
    
    switch (newNextBlockIdentifier)
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
