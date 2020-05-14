#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <string>
class Window
{
private:
    SDL_Window *sdlWindow;
public:
    enum Mode{
        WINDOWED = 0,
        BORDERLESS = SDL_WINDOW_FULLSCREEN_DESKTOP,
        FULLSCREEN = SDL_WINDOW_FULLSCREEN
    };
    Window(const std::string &title, int x, int y, int w, int h, Mode mode);
    Window(const Window& other) = delete;
    Window& operator=(const Window& other) = delete;
    int getX()const;
    int getY()const;
    void setX(int x);
    void setY(int y);
    int getWidth()const;
    int getHeight()const;
    void setWidth(int w);
    void setHeight(int h);
    void setDimensions(int w, int h);

    Mode getMode()const;
    void setMode(Mode mode);

    SDL_Renderer* createSdlRenderer();
    ~Window();
};

#endif // WINDOW_H
