#include "display-module.h"

#include <iostream>

#include <SDL2_gpu/SDL_gpu.h>

#include "data-transfer-types.h"
#include "image-bank.h"
#include "window-controller.h"
#include "rendering-unit.h"
#include "game-element.h"
#include "sprite.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;


DisplayModule::DisplayModule()
    : windowController(make_shared <WindowController> ()),
      renderingUnit(make_shared <RenderingUnit> (windowController->getWindow()))
{
    
}


void DisplayModule::refresh(WindowFlags windowFlags, vector <shared_ptr <Sprite>> sprites)
{
    if (windowFlags.fullscreen != GPU_GetFullscreen())
    {
        setFullscreen(windowFlags.fullscreen);
    }
     
    renderingUnit->drawSprites(sprites);
}


void DisplayModule::setFullscreen(bool fullscreen)
{
    windowController->setFullscreen(fullscreen);
    renderingUnit->setWindowCentre();
}
