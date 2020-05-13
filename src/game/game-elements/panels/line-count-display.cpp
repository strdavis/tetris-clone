#include "line-count-display.h"

#include "image-bank.h"
#include "sprite.h"
#include "digital-display.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


LineCountDisplay::LineCountDisplay(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),
      digitalDisplay(make_shared <DigitalDisplay> (imageBank))
{
    pos = {80, -39};
    
    background->setSize(62, 24);
    
    frame->setImage(imageBank->lineCountFrame);
    frame->setSize(78, 40);
}


void LineCountDisplay::update(int newLineCount)
{
    if (digitalDisplay->getDisplayValue() != newLineCount)
    {
        digitalDisplay->setDisplay(newLineCount);
    }
}


vector <shared_ptr <Sprite>> LineCountDisplay::getSprites()
{
    // Clear sprites vector.
    vector <shared_ptr <Sprite>> temp;
    sprites.swap(temp);
    
    sprites.push_back(background);
    sprites.push_back(frame);
    
    vector <shared_ptr <Sprite>> digitalDisplaySprites = digitalDisplay->getSprites();
    
    sprites.insert(end(sprites), begin(digitalDisplaySprites), end(digitalDisplaySprites));
    
    return GameElement::getSprites();
}
