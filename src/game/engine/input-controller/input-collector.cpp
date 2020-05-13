#include "input-collector.h"

#include <iostream>

#include <SDL2/SDL.h>

#include "data-transfer-types.h"

using std::shared_ptr;
using std::make_shared;


InputCollector::InputCollector ()
{

}


InputData InputCollector::getInput()
{
    InputData inputData = getEventInput();
    
    inputData.keyStates = getKeyStates();
    
    // InputCollector stores copy of key states for making comparisons next frame.
    // Comparisons are necessary to determine if a key was pressed or held.
    keyStatesLastFrame = inputData.keyStates;
    
    return inputData;
}


InputData InputCollector::getEventInput()
{
    InputData inputData;
    
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                inputData.quit = true;
                break;
        }
    }
    
    return inputData;
}


KeyStates InputCollector::getKeyStates()
{
    KeyStates keyStates;
    
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    
    keyStates.q = getKeyState(keyboardState, SDL_SCANCODE_Q, keyStatesLastFrame.q);
    keyStates.p = getKeyState(keyboardState, SDL_SCANCODE_P, keyStatesLastFrame.p);
    keyStates.r = getKeyState(keyboardState, SDL_SCANCODE_R, keyStatesLastFrame.r);
    keyStates.f = getKeyState(keyboardState, SDL_SCANCODE_F, keyStatesLastFrame.f);
    keyStates.z = getKeyState(keyboardState, SDL_SCANCODE_Z, keyStatesLastFrame.z);
    keyStates.x = getKeyState(keyboardState, SDL_SCANCODE_X, keyStatesLastFrame.x);
    keyStates.left = getKeyState(keyboardState, SDL_SCANCODE_LEFT, keyStatesLastFrame.left);
    keyStates.right = getKeyState(keyboardState, SDL_SCANCODE_RIGHT, keyStatesLastFrame.right);
    keyStates.down = getKeyState(keyboardState, SDL_SCANCODE_DOWN, keyStatesLastFrame.down);
    
    return keyStates;
}


KeyState InputCollector::getKeyState(const Uint8 *keyboardState,
                                     SDL_Scancode keyCode,
                                     KeyState keyStateLastFrame)
{
    KeyState keyState;
    
    // If key is depressed.
    if (keyboardState [keyCode])
    {
        if (keyStateLastFrame.pressed || keyStateLastFrame.held)
        {
            keyState.held = true;
        }
        else
        {
            keyState.pressed = true;
        }
    }
    
    return keyState;
}
