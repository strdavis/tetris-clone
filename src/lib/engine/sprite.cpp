#include "sprite.h"

#include <iostream>

#include "SDL_gpu.h"

#include "wrapped-gpu-image.h"

using std::shared_ptr;
using std::make_shared;


Sprite::Sprite(shared_ptr <WrappedGpuImage> image, int x, int y, int w, int h)
    : image(image), pos({x, y})
{
    setSize(w, h);
}


Sprite::Sprite(shared_ptr <Sprite> sprite)
    : image(sprite->getImage()),
      pos(sprite->getPos())
{
    setSize(sprite->getWidth(), sprite->getHeight());
}


Sprite::Sprite()
    : image(NULL), pos({0, 0})
{
    setSize(0, 0);
}


void Sprite::setImage(std::shared_ptr<WrappedGpuImage> newImage)
{
    image = newImage;
}


void Sprite::setSize(Uint16 w, Uint16 h)
{
    width = w;
    height = h;
}


void Sprite::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}


shared_ptr <WrappedGpuImage> Sprite::getImage()
{
    return image;
}


GPU_Image* Sprite::getRawImage()
{
    return image->getRawImage();
}


SDL_Point Sprite::getPos()
{
    return pos;
}


int Sprite::getWidth()
{
    return width;
}


int Sprite::getHeight()
{
    return height;
}

