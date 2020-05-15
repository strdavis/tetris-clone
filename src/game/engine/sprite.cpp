/*
* MIT License
*
* Copyright (c) 2020 Spencer Davis
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/


#include "sprite.h"

#include <iostream>

#include "SDL2_gpu/SDL_gpu.h"

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

