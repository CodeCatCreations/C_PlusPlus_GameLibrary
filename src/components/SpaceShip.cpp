#include "SpaceShip.h"

SpaceShip::SpaceShip(): Component(cwing::sys.getWindowWidth() / 2, cwing::sys.getWindowHeight() - 20, 40, 40), x_coordinate(cwing::sys.getWindowWidth() / 2), y_coordinate(cwing::sys.getWindowHeight() + 5) {
    texture = IMG_LoadTexture(cwing::sys.get_ren(), (constants::gResPath + "images/cats.jpeg").c_str());
}

void SpaceShip::draw() const {
    const SDL_Rect& rect = getRect();
    SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);
}

void SpaceShip::tick() {
    counter++;

}

bool SpaceShip::intersects(const SDL_Rect& otherRect) const {
    // Store the result of getRect in a local variable
    SDL_Rect rect = getRect();
    // Return false = do not want to be removed from session

    if (SDL_HasIntersection(&rect, &otherRect)) {
        // TODO: Lose life when intersecting 
        return false;
    }
    return false;
}

bool SpaceShip::checkBorder() {
    int window_max_x = cwing::sys.getWindowWidth();
    int window_max_y = cwing::sys.getWindowHeight();

    if (rect.x >= (window_max_x - steps) ||
        rect.x <= steps ||
        rect.y >= window_max_y ||
        rect.y <= steps) {
        return false;
    }
    return true;

}

void SpaceShip::keyDown() {
    if (checkBorder()) {
        rect.y += steps;
    }
}
void SpaceShip::keyUp() {
    if (checkBorder()) {
        rect.y -= steps;
    }
}
void SpaceShip::keyLeft() {
    if (checkBorder()) {
        rect.x -= steps;
    }
}
void SpaceShip::keyRight() {
    if (checkBorder()) {
        rect.x += steps;
    }
}

