#include "window.h"
#include <SDL2/SDL.h>
#include <string>
using namespace std;

Window::Window(const string& title, int x, int y, int w, int h, Mode mode)
{
    this->sdlWindow = SDL_CreateWindow(title.c_str(), x,y,w,h,mode);
}

int Window::getX() const
{
    int x = -1;
    SDL_GetWindowPosition(this->sdlWindow, &x,NULL);
    return x;
}

int Window::getY() const
{
    int y = -1;
    SDL_GetWindowPosition(this->sdlWindow, NULL, &y);
    return y;
}

void Window::setX(int x)
{
    SDL_SetWindowPosition(this->sdlWindow, x, this->getY());
}

void Window::setY(int y)
{
    SDL_SetWindowPosition(this->sdlWindow, this->getX(), y);
}

int Window::getWidth() const
{
    int w = -1;
    SDL_GetWindowSize(this->sdlWindow, &w, NULL);
    return w;
}

int Window::getHeight() const
{
    int h = -1;
    SDL_GetWindowSize(this->sdlWindow, NULL, &h);
    return h;
}

void Window::setWidth(int w)
{
    SDL_SetWindowSize(this->sdlWindow,w, this->getHeight());
}

void Window::setHeight(int h)
{
    SDL_SetWindowSize(this->sdlWindow, this->getWidth(), h);
}

void Window::setDimensions(int w, int h)
{
    SDL_SetWindowSize(this->sdlWindow, w, h);
}

Window::Mode Window::getMode() const
{
    Uint32 flags = SDL_GetWindowFlags(this->sdlWindow);
    return Window::Mode((flags & SDL_WINDOW_FULLSCREEN) | (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) | 0);
}

void Window::setMode(Window::Mode mode)
{
    SDL_SetWindowFullscreen(this->sdlWindow, mode);
}

SDL_Renderer* Window::createSdlRenderer()
{
    return SDL_CreateRenderer(this->sdlWindow,-1, SDL_RENDERER_ACCELERATED);
}

Window::~Window()
{
    SDL_DestroyWindow(this->sdlWindow);
}
