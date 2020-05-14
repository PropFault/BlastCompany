#include "imagetexturecomponent.h"
#include <SDL2/SDL_image.h>
#include <stdexcept>
using namespace std;
ImageTextureComponent::ImageTextureComponent(SDL_Renderer *renderer)
    :texture(NULL),renderer(renderer)
{
}

ImageTextureComponent::ImageTextureComponent(const ImageTextureComponent &othr)
{
    this->renderer = othr.renderer;
}

std::string ImageTextureComponent::getName()
{
    return Texture::COMPONENT_IDENTIFIER;
}

Component *ImageTextureComponent::clone()
{
    return new ImageTextureComponent(*this);
}

ImageTextureComponent::init(nlohmann::json json)
{

}
