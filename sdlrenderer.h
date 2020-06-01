#ifndef RENDERER_H
#define RENDERER_H
#include "rect.h"
#include "texture.h"
#include <SDL2/SDL.h>
class SDLRenderer{
private:
    SDL_Renderer *sdlRenderer;
    int pixelPerUnit;
public:
    SDLRenderer(SDL_Renderer* owningRenderer, int virtViewportW = 1280, int virtViewportH = 720, int pixelPerUnit = 100, bool forceViewportPerfectIntegers = false);
    SDLRenderer(const SDLRenderer& othr) = delete;
    void renderRect(const Rect &rect, const Texture &texs);
    int getPixelPerUnit() const;
    void setPixelPerUnit(int value);
    void present();
    SDLRenderer& operator=(const SDLRenderer &othr) = delete;
    ~SDLRenderer();
    SDL_Renderer *getSdlRenderer() const;
    void setSdlRenderer(SDL_Renderer *value);
};

#endif // RENDERER_H
