#include "high-score-display.h"

#include <iostream>

#include "image-bank.h"
#include "sprite.h"
#include "digital-display.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


HighScoreDisplay::HighScoreDisplay(shared_ptr <ImageBank> imageBank)
    : Panel(imageBank),
      digitalDisplay(make_shared <DigitalDisplay> (imageBank))
{    
    pos = {80, 27};
    
    background->setSize(62, 24);
    
    frame->setImage(imageBank->highScoreFrame);
    frame->setSize(78, 40);
}


void HighScoreDisplay::update(int newHighScore)
{
    if (digitalDisplay->getDisplayValue() != newHighScore)
    {
        digitalDisplay->setDisplay(newHighScore);
    }
}


vector <shared_ptr <Sprite>> HighScoreDisplay::getSprites()
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

