#include "GameEngine.h"
#include "Session.h"
#include "Sprite.h"
#include "Component.h"

#include <vector>

namespace cwing {
    GameEngine::GameEngine() {}

    GameEngine::~GameEngine() {}

    void GameEngine::addSprite(Component* sprite) {
        sprites.push_back(sprite);
    }

    void GameEngine::run() {
        Session session;
        for (Component* sprite : sprites) {
            session.add(sprite);
        }
        session.run();
    }
} // namespace cwing