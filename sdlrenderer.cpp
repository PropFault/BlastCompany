#include "sdlrenderer.h"
#include <stdexcept>
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

SDLRenderer::SDLRenderer(SDL_Renderer *owningRenderer, int virtViewportW, int virtViewportH, int pixelPerUnit, bool forceIntScaling)
    :sdlRenderer(owningRenderer),pixelPerUnit(pixelPerUnit)
{
    SDL_RenderSetLogicalSize(this->sdlRenderer,virtViewportW, virtViewportH);
    if(forceIntScaling){
        SDL_RenderSetIntegerScale(this->sdlRenderer, SDL_TRUE);
        throw std::runtime_error("This is broken. It needs to be fixed. The SDL wiki is down right now but for some reason this prevents stuff from getting drawn.Please disable forceIntScaling when making a new sdlrenderer to get rid of this message.");
    }
}


int toSdl(float coordIn, int pxPU){
    return coordIn * pxPU;
}


void SDLRenderer::renderRect(const Rect &rect, const Texture &texs)
{
    SDL_Rect rct;
    int logicalW=0;
    int logicalH=0;
    SDL_RenderGetLogicalSize(this->sdlRenderer, &logicalW, &logicalH);
    rct.x = toSdl(rect.getOrigin().getX(), this->pixelPerUnit) + logicalW/2 - toSdl(rect.getWidth()/2, this->pixelPerUnit);
    rct.y = toSdl(rect.getOrigin().getY() ,this->pixelPerUnit) + logicalH/2 - toSdl(rect.getHeight()/2, this->pixelPerUnit);
    rct.w = toSdl(rect.getWidth(), this->pixelPerUnit);
    rct.h = toSdl(rect.getHeight(), this->pixelPerUnit);
    SDL_RenderCopy(this->sdlRenderer,texs.getSDLTexture(),NULL,&rct);
}
