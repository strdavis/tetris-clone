#pragma once

#include <memory>

class GPU_Image;


// Wrapper class for GPU_Image.
// Automatically frees the image when it is deleted.
class WrappedGpuImage
{
public:
    WrappedGpuImage(const char *path);
    
    ~WrappedGpuImage();
    
    GPU_Image* getRawImage();

private:
    GPU_Image* image;
};
