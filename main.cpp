#include <iostream>
#include "window.h"
#include "sdlrenderer.h"
#include "rect.h"
using namespace std;

int main()
{
    Window window("Testscreen", 100,100,600,600, Window::Mode::WINDOWED);
    SDLRenderer renderer(window.createSdlRenderer());
    renderer.present();
    getchar();
    return 0;
}
