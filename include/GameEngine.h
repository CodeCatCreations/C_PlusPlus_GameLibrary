#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Component.h"
#include "Session.h"
#include "Sprite.h"
#include "System.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <vector>

namespace cwing {

    class GameEngine {
    public:
        GameEngine(): session() {}
        void removeSprite(Component* sprite);
        void addSprite(Component* sprite);
        void run(); // Runs the event loop and updates and draws sprites

    private:
        Session session;
        std::vector<Component*> sprites; // Sprites to update and draw
    };

} // namespace cwing

#endif

