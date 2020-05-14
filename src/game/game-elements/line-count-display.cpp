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
