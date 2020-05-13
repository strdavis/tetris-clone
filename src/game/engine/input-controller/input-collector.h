#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_Scancode.h>

#include "data-transfer-types.h"


// Can be queried for current input.
// Current input is returned as a struct of booleans
// corresponding to input events / key states.
// Stores a copy of the last-recorded input.
class InputCollector
{
public:
    InputCollector();
    
    InputData getInput();
    
private:
    InputData getEventInput();
    KeyStates getKeyStates();
    KeyState getKeyState(const Uint8 *keyboardState,
                                 SDL_Scancode keyCode,
                                 KeyState keyStateLastFrame);
    
    KeyStates keyStatesLastFrame;
};

