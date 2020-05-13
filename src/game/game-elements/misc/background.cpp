#include "background.h"

#include <iostream>

#include "image-bank.h"
#include "sprite.h"

using std::shared_ptr;
using std::make_shared;


Background::Background (shared_ptr <ImageBank> imageBank)
    : GameElement(imageBank),
      firstLayer(make_shared <Sprite> (imageBank->darkGrey))
{
    firstLayer->setSize(1000, 1000);

}
