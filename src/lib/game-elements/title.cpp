#include "title.h"

#include "SDL_rect.h"

#include "image-bank.h"
#include "sprite.h"

using std::shared_ptr;
using std::make_shared;


Title::Title(shared_ptr <ImageBank> imageBank)
    : GameElement(imageBank),
      titleImage(make_shared <Sprite> (imageBank->title))
{
    pos = {-83, 72};
    
    titleImage->setSize(79, 30);
    
    sprites.push_back(titleImage);
}
