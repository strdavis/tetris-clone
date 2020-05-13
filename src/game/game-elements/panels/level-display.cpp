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


#include "level-display.h"

#include "image-bank.h"
#include "sprite.h"

using std::shared_ptr;
using std::make_shared;


LevelDisplay::LevelDisplay(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),
      levelDisplayed(0),
      levelSprite(make_shared <Sprite> ())
{
    sprites.push_back(levelSprite);
    
    pos = {100, 64};
    
    background->setImage(imageBank->white);
    background->setSize(21, 32);
    
    frame->setImage(imageBank->levelFrame);
    frame->setSize(29, 40);
    
    levelSprite->setImage(imageBank->level1);
    levelSprite->setPos(0, -4);
    levelSprite->setSize(20, 20);
    
    
}


void LevelDisplay::update(int level)
{
    if (level != levelDisplayed)
    {
        levelDisplayed = level;
        
        setLevelSprite(level);
    }
}


void LevelDisplay::setLevelSprite(int level)
{
    shared_ptr <WrappedGpuImage> levelImage;
    
    switch (level)
    {
        case 1:
            levelImage = imageBank->level1;
            break;
            
        case 2:
            levelImage = imageBank->level2;
            break;
            
        case 3:
            levelImage = imageBank->level3;
            break;
            
        case 4:
            levelImage = imageBank->level4;
            break;
            
        case 5:
            levelImage = imageBank->level5;
            break;
            
        case 6:
            levelImage = imageBank->level6;
            break;
            
        case 7:
            levelImage = imageBank->level7;
            break;
            
        case 8:
            levelImage = imageBank->level8;
            break;
            
        case 9:
            levelImage = imageBank->level9;
            break;
    }
    
    levelSprite->setImage(levelImage);
}
