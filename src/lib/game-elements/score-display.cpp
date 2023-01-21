#include "score-display.h"

#include <iostream>

#include "image-bank.h"
#include "sprite.h"
#include "digital-display.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


ScoreDisplay::ScoreDisplay(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),
      digitalDisplay(make_shared <DigitalDisplay> (imageBank))
{
    pos = {80, -6};
    
    background->setSize(62, 24);
    
    frame->setImage(imageBank->scoreFrame);
    frame->setSize(78, 40);
}


void ScoreDisplay::update(int newScore)
{
    if (digitalDisplay->getDisplayValue() != newScore)
    {
        digitalDisplay->setDisplay(newScore);
    }
}


vector <shared_ptr <Sprite>> ScoreDisplay::getSprites()
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
