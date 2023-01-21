#pragma once

#include <memory>

#include "SDL_stdinc.h"
#include "SDL_rect.h"

class WrappedGpuImage;
struct GPU_Image;


// Represents an image with a corresponding position and size.
//
// Sprites do not contain image data, keeping them lightweight.
// They point to images in the image bank,
// and contain information about how to draw those images.
//
// Coordinates for sprites are relative to the position of
// the game element that owns them.
class Sprite
{
public:
    Sprite(std::shared_ptr <WrappedGpuImage> image, int x = 0, int y = 0, int w = 0, int h = 0);
    Sprite(std::shared_ptr <Sprite> sprite);
    Sprite();
    
    void setImage(std::shared_ptr <WrappedGpuImage> newImage);
    void setSize(Uint16 w, Uint16 h);
    void setPos(int x, int y);
    int getWidth();
    int getHeight();
    SDL_Point getPos();
    GPU_Image* getRawImage();
    std::shared_ptr <WrappedGpuImage> getImage();

private:
    int width;
    int height;
    SDL_Point pos;
    std::shared_ptr <WrappedGpuImage> image;
};
