#ifndef PISTOL_H
#define PISTOL_H

#include "Bullet.h"
#include <SDL2/SDL.h>
#include "Session.h"
#include "Component.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>

extern cwing::Session ses;

class Pistol: public cwing::Component {
public:
    Pistol();
    void draw() const;
    void tick();
    void mouseDown(int x, int y);
};

#endif // PISTOL_H
