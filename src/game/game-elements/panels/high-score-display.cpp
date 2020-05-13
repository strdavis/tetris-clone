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

