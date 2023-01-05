#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "System.h"
#include "Session.h"
#include "Sprite.h"
#include "Component.h"

#include <vector>

namespace cwing {

    class GameEngine {
    public:
        GameEngine();
        ~GameEngine();
        void addSprite(Component* sprite);
        void run(); // Runs the event loop and updates and draws sprites

    private:
        std::vector<Component*> sprites; // Sprites to update and draw
    };

} // namespace cwing

#endif

