#include "src/Engine/Screen.h"
#include "src/Engine/Surface.h"

namespace Falltergeist
{

const double Screen::BASE_WIDTH = 640.0;
const double Screen::BASE_HEIGHT = 480.0;

Screen::Screen(int width, int height, int bpp)
{
    std::cout << "Setting up video mode " << width << "x" << height << "x" << bpp << "...";
    _screen = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE);
    SDL_SetAlpha(_screen, SDL_SRCALPHA, 0);
    if (_screen == 0)
    {
        std::cout << "[FAIL]" << std::endl;
    }
    std::cout << "[OK]" << std::endl;

    _surface = new Surface(width,height);
    _surface->setBackgroundColor(0xFF000000);
}

Screen::~Screen()
{
    delete _surface;
}

Surface * Screen::getSurface()
{
    return _surface;
}

void Screen::clear()
{
    //_surface->fill(0xFF000000);
    _surface->clear();
}

int Screen::getHeight()
{
    return _screen->h;
}

int Screen::getWidth()
{
    return _screen->w;
}

void Screen::flip()
{
    SDL_BlitSurface(_surface->getSurface(), 0, _screen, 0);


    if (SDL_Flip(_screen) == -1)
    {
        std::cout << "[ERROR]Can't flip screen" << std::endl;
        throw Exception(SDL_GetError());
    }
}

}