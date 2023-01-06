#include "Bullet.h"

Bullet::Bullet(int x, int y): Component(x, 500, 40, 40), mouse_y(y) {
    texture = IMG_LoadTexture(cwing::sys.get_ren(), (constants::gResPath + "images/cats.jpeg").c_str());
}

Bullet::~Bullet() {
    SDL_DestroyTexture(texture);
}

void Bullet::draw() const {
    const SDL_Rect& rect = getRect();
    SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);
}

void Bullet::tick() {
    counter++;
    if (rect.y <= mouse_y)
        ses.remove(this);
    else if (counter % 10 == 0)
        rect.y -= 10;
}
