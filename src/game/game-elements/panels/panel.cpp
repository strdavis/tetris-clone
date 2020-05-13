#include "panel.h"

#include "image-bank.h"
#include "sprite.h"

using std::shared_ptr;
using std::make_shared;


Panel::Panel(shared_ptr <ImageBank> imageBank)
    : GameElement(imageBank),
      background(make_shared <Sprite> ()),
      frame(make_shared <Sprite> ())
{
    // Default images / size.
    background->setImage(imageBank->white);
    frame->setImage(imageBank->nextBlockFrame);
    
    background->setSize(10, 10);
    frame->setSize(12, 12);
    
    sprites.push_back(background);
    sprites.push_back(frame);
}
