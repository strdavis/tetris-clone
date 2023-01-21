#include <iostream>
#include "SDL.h"
#include "SDL_gpu.h"
#include "engine.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    string project_root_dir = argv[1];

    Engine* engine = new Engine(project_root_dir);
    engine->runGameLoop();

    return 0;
}

// void limitFPS(int fps, int frameStartTime)
// {
//     int frameDuration = 1000 / fps;
//     int frameEndTime;
//     int ticksElapsed;
//     int ticksRemaining;
    
//     frameEndTime = SDL_GetTicks();
//     ticksElapsed = frameEndTime - frameStartTime;
//     ticksRemaining = frameDuration - ticksElapsed;
    
//     if (ticksRemaining > 0)
//     {
//         SDL_Delay(ticksRemaining);
//     }
// }

// int main(int argc, char* argv[])
// {
//     string project_root_dir = argv[1];

//     GPU_SetDebugLevel(GPU_DEBUG_LEVEL_MAX);

//     GPU_Target* window = GPU_Init(980, 704, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
//     if (window == NULL)
//     {
//         cout << "Failed to initialize window." << endl;
//         GPU_Quit();
//         return 0;
//     }

//     GPU_SetVirtualResolution(window, 245, 176);
//     SDL_SetRelativeMouseMode(SDL_FALSE);

//     string dark_grey_rel_path = "images/colours/dark-grey.png";
//     string dark_grey_abs_path = project_root_dir + dark_grey_rel_path;
//     GPU_Image* dark_grey = GPU_LoadImage(dark_grey_abs_path.c_str());
//     SDL_Point* absPos = new SDL_Point({0, 0});

//     int fps = 60;
//     int frameStartTime;
//     bool quit = false;
//     while (!quit)
//     {
//         frameStartTime = SDL_GetTicks();

//         SDL_Event event;
//         while (SDL_PollEvent(&event))
//         {
//             switch (event.type)
//             {
//                 case SDL_QUIT:
//                     quit = true;
//                     break;
//             }
//         }

//         //displayModule->refresh(gameState->getWindowFlags(), gameState->getSprites());
        
//         GPU_Clear(window);
//         GPU_Blit(dark_grey, NULL, window, absPos->x, absPos->y);
//         GPU_Flip(window);
//         limitFPS(fps, frameStartTime);
//     }

//     GPU_FreeImage(dark_grey);
//     GPU_Quit();
//     return 0;
// }