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
