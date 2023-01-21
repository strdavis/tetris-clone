#pragma once

#include <memory>

struct GPU_Target;
class SdlInitializer;


// Controls fullscreen mode and window dimensions.
class WindowController
{
public:
    WindowController();

    void setFullscreen(bool fullscreen);
    GPU_Target* getWindow();
    
private:
    void setWindowTitle(const char *title);
    void setVirtualFullscreenDimensions();
    
    int widthWindowed;
    int heightWindowed;
    int virtualWidthWindowed;
    int virtualHeightWindowed;
    int virtualWidthFullscreen;
    int virtualHeightFullscreen;
    GPU_Target *window;
    std::shared_ptr <SdlInitializer> sdlInitializer;
};


