#include "wrapped-gpu-image.h"

#include <iostream>

#include <SDL2_gpu/SDL_gpu.h>


WrappedGpuImage::WrappedGpuImage(const char *path)
    : image(GPU_LoadImage(path))
{
    
}


WrappedGpuImage::~WrappedGpuImage()
{
    GPU_FreeImage(image);
}


GPU_Image* WrappedGpuImage::getRawImage()
{
    return image;
}
