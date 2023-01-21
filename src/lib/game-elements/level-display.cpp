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
