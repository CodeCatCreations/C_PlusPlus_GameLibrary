#include "Bullet.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>


Bullet::Bullet(int x, int y): Component(x - 20, 400, 40, 40), mouse_x(x), mouse_y(y) {
    texture = IMG_LoadTexture(cwing::sys.get_ren(), (constants::gResPath + "images/bullet.png").c_str());
    sound = Mix_LoadWAV((constants::gResPath + "sounds/shot.mp3").c_str());
    sound_played = false;
}


Bullet::~Bullet() {
    SDL_DestroyTexture(texture);
    Mix_FreeChunk(sound);
}

void Bullet::draw() const {
    const SDL_Rect& rect = getRect();
    SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);

    if (!sound_played) {
        Mix_PlayChannel(-1, sound, 0);
        sound_played = true;
    }
}

void Bullet::tick() {

    counter++;
    if (rect.y <= mouse_y)
        cwing::ses.remove(this);
    else if (counter % 10 == 0)
        rect.y -= 10;

}
