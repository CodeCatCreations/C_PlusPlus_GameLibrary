#include "SpaceShip.h"


SpaceShip::SpaceShip(): Sprite(cwing::sys.getWindowWidth() / 2 - 50,
    cwing::sys.getWindowHeight() - 100, 100, 100),
    x_coordinate(cwing::sys.getWindowWidth() / 2 - 50),
    y_coordinate(cwing::sys.getWindowHeight() - 100) {}

SpaceShip::SpaceShip(int x, int y, int w, int h): Sprite(x, y, w, h),
x_coordinate(x),
y_coordinate(y) {
    texture = IMG_LoadTexture(cwing::sys.get_ren(), (constants::gResPath + "images/cats.jpeg").c_str());
}

void SpaceShip::draw() const {
    const SDL_Rect& rect = getRect();
    SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);
}

void SpaceShip::tick() {
    // Move and draw the bullets
    rect.x = x_coordinate;
    rect.y = y_coordinate;
    for (Bullet* bullet : bullets) {
        bullet->tick();
        bullet->draw();
    }

}

void SpaceShip::handleMouseDown(int x, int y) {
    // Create a new bullet at the mouse coordinates
    Bullet* bullet = new Bullet(x, y);
    bullets.push_back(bullet);
}

void SpaceShip::shoot() {
    Bullet* bullet = new Bullet(x_coordinate, y_coordinate);
    bullets.push_back(bullet);
}

void SpaceShip::keyDown() {
    // Update the y-coordinate of the spaceship to move it down
    y_coordinate += 10;
}

void SpaceShip::keyUp() {
    // Update the y-coordinate of the spaceship to move it up
    y_coordinate -= 10;
}

void SpaceShip::keyLeft() {
    // Update the x-coordinate of the spaceship to move it left
    x_coordinate -= 10;
}

void SpaceShip::keyRight() {
    // Update the x-coordinate of the spaceship to move it right
    x_coordinate += 10;
}
