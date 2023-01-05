#ifndef BULLET_H
#define BULLET_H

#include "Constants.h"
#include <SDL2/SDL.h>
#include "Session.h"
#include "Component.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>

extern cwing::Session ses;

class Bullet: public cwing::Component {

public:
    static Bullet* getInstance(int x) {
        return new Bullet(x);
    }
    Bullet(int x);
    ~Bullet();
    void draw() const;
    void tick();

private:
    SDL_Texture* texture;
    int counter = 0;
};

#endif 
