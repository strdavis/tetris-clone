#pragma once


// Library of types used to transfer information
// between engine components and game elements.
//
// Engine components can be variously queried
// to return these "packets", which can then
// be sent to the update() functions
// of the appropriate game elements.


struct KeyState
{
    bool pressed {false};
    bool held {false};
};


struct KeyStates
{
    KeyState q;
    KeyState p;
    KeyState r;
    KeyState f;
    KeyState z;
    KeyState x;
    KeyState left;
    KeyState right;
    KeyState down;
};


struct InputData
{
    bool quit {false};
    
    KeyStates keyStates;
};


struct WindowFlags
{
    bool fullscreen;
};


struct SaveData
{
    int highScore {0};
};
