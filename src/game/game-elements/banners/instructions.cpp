#include "instructions.h"

#include "image-bank.h"
#include "sprite.h"

using std::shared_ptr;
using std::make_shared;


Instructions::Instructions(shared_ptr <ImageBank> imageBank)
    : GameElement(imageBank),
      instructionsImage(make_shared <Sprite> (imageBank->instructions))
{
    pos = {86, -70};
    
    instructionsImage->setSize(79, 30);
    
    sprites.push_back(instructionsImage);
}
