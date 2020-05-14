#include "sdlrenderer.h"

int SDLRenderer::getPixelPerUnit() const
{
    return pixelPerUnit;
}

void SDLRenderer::setPixelPerUnit(int value)
{
    pixelPerUnit = value;
}

void SDLRenderer::present()
{
    SDL_RenderPresent(this->sdlRenderer);
}

SDLRenderer::~SDLRenderer()
{
    SDL_DestroyRenderer(this->sdlRenderer);
}

SDLRenderer::SDLRenderer(SDL_Renderer *owningRenderer, int virtViewportW, int pixelPerUnit, int virtViewportH, bool forceIntScaling)
    :sdlRenderer(owningRenderer)
{
    SDL_RenderSetLogicalSize(this->sdlRenderer,virtViewportW, virtViewportH);
    if(forceIntScaling)
        SDL_RenderSetIntegerScale(this->sdlRenderer, SDL_TRUE);
}


int toSdl(float coordIn, int pxPU){
    return coordIn * pxPU;
}

void SDLRenderer::renderRect(const Rect &rect, const Texture &texs)
{
    SDL_Rect rct;
    rct.x = toSdl(rect.getOrigin().getX() - rect.getWidth()/2.0, this->pixelPerUnit);
    rct.y = toSdl(rect.getOrigin().getY() - rect.getHeight()/2.0,this->pixelPerUnit);
    rct.w = toSdl(rect.getWidth(), this->pixelPerUnit);
    rct.h = toSdl(rect.getHeight(), this->pixelPerUnit);
    SDL_RenderCopy(this->sdlRenderer,texs.getSDLTexture(),NULL,&rct);
}
