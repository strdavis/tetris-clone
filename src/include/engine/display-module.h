#pragma once

#include <memory>
#include <vector>

struct WindowFlags;

class WindowController;
class RenderingUnit;
class GameElement;
class Sprite;


// Contains engine components for rendering / display.
class DisplayModule
{
public:
    DisplayModule();
    
    void refresh(WindowFlags windowFlags, std::vector <std::shared_ptr <Sprite>> sprites);
    void setFullscreen(bool fullscreen);
    
private:
    std::shared_ptr <WindowController> windowController;
    std::shared_ptr <RenderingUnit> renderingUnit;
};

