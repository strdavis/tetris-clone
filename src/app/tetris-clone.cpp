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