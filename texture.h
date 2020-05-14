#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <string>
class Texture
{
public:
    static const std::string COMPONENT_IDENTIFIER;
    virtual SDL_Texture* getSDLTexture()const = 0;
    virtual ~Texture(){};
};

#endif // TEXTURE_H
