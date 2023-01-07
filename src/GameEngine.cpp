#include "GameEngine.h"
#include <vector>

namespace cwing {

    void GameEngine::run() {
        for (Component* sprite : sprites) {
            session.add(sprite);
        }
        session.run();
    }

    void GameEngine::removeSprite(Component* sprite) {
        // Find the sprite in the list of sprites and remove it
        for (unsigned int i = 0; i < sprites.size(); i++) {
            if (sprites[i] == sprite) {
                sprites.erase(sprites.begin() + i);
                break;
            }
        }
        session.remove(sprite);
    }

    void GameEngine::addSprite(Component* sprite) {
        sprites.push_back(sprite);
    }

} // namespace cwing