#ifndef IMAGETEXTURECOMPONENT_H
#define IMAGETEXTURECOMPONENT_H
#include "component.h"
#include "texture.h"
#include <string>
#include <SDL2/SDL.h>
class ImageTextureComponent : public Texture, public Component
{
private:
    SDL_Texture *texture;
    SDL_Renderer *renderer;
public:
    ImageTextureComponent(SDL_Renderer *renderer);
    ImageTextureComponent(const ImageTextureComponent& othr);
    ImageTextureComponent& operator=(const ImageTextureComponent& othr);
    // Component interface
public:
    std::string getName();
    Component *clone();

    // Texture interface
public:
    SDL_Texture *getSDLTexture() const;

    // Component interface
public:
    init(nlohmann::json json);
    deinit(nlohmann::json json);
};

#endif // IMAGETEXTURECOMPONENT_H
