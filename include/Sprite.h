#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "Session.h"
#include "System.h"
#include <SDL2/SDL_image.h>

extern cwing::Session ses;

class Sprite: public cwing::Component {
public:
    Sprite(int x, int y, int w, int h): Component(x, y, w, h) {};
    virtual ~Sprite() {};
    virtual void draw() const = 0;
    virtual void tick() = 0;
};


#endif