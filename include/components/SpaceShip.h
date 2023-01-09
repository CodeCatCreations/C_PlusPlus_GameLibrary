#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Sprite.h"
#include "Bullet.h"

#include <vector>

extern cwing::Session ses;

class SpaceShip: public cwing::Component {
public:
    SpaceShip();
    static SpaceShip* getInstance() {
        return new SpaceShip();
    }
    ~SpaceShip() {}

    void draw() const override;
    void tick() override;
    void handleMouseDown(int x, int y) {}
    void shoot() {}
    void keyDown();
    void keyUp();
    void keyLeft();
    void keyRight();
    bool intersects(const SDL_Rect& rect) const override;

private:
    bool checkBorder();
    std::vector<Bullet*> bullets;
    int x_coordinate;
    int y_coordinate;
    int counter = 0;
    SDL_Texture* texture;
    const int steps = 5;
};

#endif  // SPACESHIP_H
