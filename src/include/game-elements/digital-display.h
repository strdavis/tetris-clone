#pragma once

#include <memory>

#include "game-element.h"

class WrappedGpuImage;


// Digits-only (no frame or background).
// Max display value is 999999.
// Does not display leading zeroes.
// Display values are left-aligned.
class DigitalDisplay : public GameElement
{
public:
    DigitalDisplay(std::shared_ptr <ImageBank> imageBank, int x = 0, int y = 0);
    
    void setDisplay(int newDisplayValue);
    void resetDisplay();
    int getDisplayValue();
    
private:
    void setDigit(std::shared_ptr <Sprite> digit);
    std::shared_ptr <WrappedGpuImage> getImageForDigit(int value);
    std::vector <int> getDigitValues(int number);
    
    int displayValue;
};
