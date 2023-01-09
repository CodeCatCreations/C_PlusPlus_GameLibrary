#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Sprite.h"
#include "Bullet.h"

#include <vector>

class SpaceShip: public Sprite {
public:
    SpaceShip();
    SpaceShip(int x, int y, int w, int h);
    ~SpaceShip() {}

    void draw() const override;
    void tick() override;
    void handleMouseDown(int x, int y);
    void shoot();
    void keyDown();
    void keyUp();
    void keyLeft();
    void keyRight();

private:
    std::vector<Bullet*> bullets;
    int x_coordinate;
    int y_coordinate;
    int counter = 0;
    SDL_Texture* texture;
};

#endif  // SPACESHIP_H
