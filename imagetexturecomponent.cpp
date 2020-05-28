#include "imagetexturecomponent.h"
#include <SDL2/SDL_image.h>
#include <stdexcept>
#include <iostream>
using namespace std;

const string ImageTextureComponent::ARG_FILEPATH = "filepath";
ImageTextureComponent::ImageTextureComponent(SDL_Renderer *renderer)
    :Component(Texture::COMPONENT_IDENTIFIER),texture(NULL),renderer(renderer)
{
    IMG_Init(IMG_INIT_PNG);
}

ImageTextureComponent::ImageTextureComponent(const ImageTextureComponent &othr)
    :Component(othr.getTypeName())
{
    this->renderer = othr.renderer;
}


Component *ImageTextureComponent::clone()
{
    return new ImageTextureComponent(*this);
}

void ImageTextureComponent::_init(nlohmann::json json)
{
    std::cout<<"INIT IMAGE CONCRETE WITH " << json << std::endl;
    string path = json[ARG_FILEPATH].get<std::string>();
    SDL_Surface* surf = IMG_Load(path.c_str());
    if(surf != NULL){
        this->texture = SDL_CreateTextureFromSurface(this->renderer, surf);
        SDL_FreeSurface(surf);
    }else {
        throw runtime_error((string("COULD NOT LOAD IMAGE AT PATH")+path).c_str());
    }

}

void ImageTextureComponent::_deinit()
{
    if(this->texture != NULL){
        SDL_DestroyTexture(this->texture);
        this->texture = NULL;
    }
}

SDL_Texture *ImageTextureComponent::getSDLTexture() const
{
    return this->texture;
}
