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


#include "digital-display.h"

#include <iostream>

#include "image-bank.h"
#include "sprite.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


DigitalDisplay::DigitalDisplay(shared_ptr <ImageBank> imageBank, int x, int y)
    : GameElement(imageBank, x, y)
{
    setDisplay(0);
}


void DigitalDisplay::setDisplay(int newDisplayValue)
{
    // Clear sprites vector.
    vector <shared_ptr <Sprite>> temp;
    sprites.swap(temp);
    
    vector <int> digitValues = getDigitValues(newDisplayValue);
    
    int digitPosX = -25;
    
    for (auto value : digitValues)
    {
        shared_ptr <WrappedGpuImage> digitImage = getImageForDigit(value);
        shared_ptr <Sprite> digitSprite = make_shared <Sprite> (digitImage, digitPosX, -4, 12, 12);
        sprites.push_back(digitSprite);
        
        digitPosX += 10;
    }
    
    displayValue = newDisplayValue;
}


// Returns vector of inidividual digits from a number.
vector <int> DigitalDisplay::getDigitValues(int number)
{
    vector <int> digitValues;
    
    if (number == 0)
    {
        digitValues.push_back(0);
    }
    else
    {
        // Stores digits in vector, in reverse order.
        while (number > 0)
        {
            digitValues.push_back(number % 10);
            number /= 10;
        }
        
        reverse(digitValues.begin(), digitValues.end());
    }
    
    return digitValues;
}


shared_ptr <WrappedGpuImage> DigitalDisplay::getImageForDigit(int value)
{
    switch (value)
    {
        case 0:
            return imageBank->digit0;
            
        case 1:
            return imageBank->digit1;
            
        case 2:
            return imageBank->digit2;
            
        case 3:
            return imageBank->digit3;
            
        case 4:
            return imageBank->digit4;
            
        case 5:
            return imageBank->digit5;
            
        case 6:
            return imageBank->digit6;
            
        case 7:
            return imageBank->digit7;
            
        case 8:
            return imageBank->digit8;
            
        case 9:
            return imageBank->digit9;
            
        default:
            return nullptr;
    }
}


int DigitalDisplay::getDisplayValue()
{
    return displayValue;
}
