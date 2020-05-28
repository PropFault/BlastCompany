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
    static const std::string ARG_FILEPATH;
    ImageTextureComponent(SDL_Renderer *renderer);
    ImageTextureComponent(const ImageTextureComponent& othr);
    ImageTextureComponent& operator=(const ImageTextureComponent& othr);
    // Component interface
public:
    virtual Component *clone()override;
private:
    virtual void _init(nlohmann::json json)override;
    virtual void _deinit()override;
    // Texture interface
public:
    virtual SDL_Texture *getSDLTexture() const override;
};

#endif // IMAGETEXTURECOMPONENT_H
