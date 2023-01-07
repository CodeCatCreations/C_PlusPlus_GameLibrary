#include "Constants.h"
#include "sprites/Goblin.h"
#include "Sprite.h"
#include <SDL2/SDL.h>


Goblin::Goblin(int x, int w, int h): Sprite(x, 0, w, h), width(w), height(h) {
	texture = IMG_LoadTexture(cwing::sys.get_ren(), (constants::gResPath + imgPath).c_str());
}

Goblin::~Goblin() {}

void Goblin::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);
}

void Goblin::tick() {

	counter++;
	if (rect.y >= 500)
		ses.remove(this);
	else if (counter % 100 == 0)
		rect.y += 2;

}