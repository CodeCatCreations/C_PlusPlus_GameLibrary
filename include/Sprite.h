#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"

namespace cwing {
    class Sprite: public Component {
    public:
        Sprite(int x, int y, int w, int h);
        virtual void draw() const = 0;
        virtual void tick() = 0;
    };
} // namespace cwing

#endif