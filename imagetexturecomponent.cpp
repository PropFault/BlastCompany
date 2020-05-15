#include "imagetexturecomponent.h"
#include <SDL2/SDL_image.h>
#include <stdexcept>
#include <iostream>
using namespace std;
ImageTextureComponent::ImageTextureComponent(SDL_Renderer *renderer)
    :Component(Texture::COMPONENT_IDENTIFIER),texture(NULL),renderer(renderer)
{
}

ImageTextureComponent::ImageTextureComponent(const ImageTextureComponent &othr)
    :Component(othr.getName())
{
    this->renderer = othr.renderer;
}


Component *ImageTextureComponent::clone()
{
    return new ImageTextureComponent(*this);
}

void ImageTextureComponent::init(nlohmann::json json)
{
    cout<<"init on imagetexturecomponent called with " << json<<endl;
}

void ImageTextureComponent::deinit()
{
    cout<<"deinit on imagetexturecomponent called"<<endl;
}

SDL_Texture *ImageTextureComponent::getSDLTexture() const
{
    return this->texture;
}
