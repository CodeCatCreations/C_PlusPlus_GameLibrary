#include "Constants.h"
#include "Goblin.h"
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include <iostream>

std::vector<Goblin*> Goblin::goblins;

Goblin::Goblin(int x, int w, int h): Sprite(x, 0, w, h), width(w), height(h) {
	texture = IMG_LoadTexture(cwing::sys.get_ren(), (constants::gResPath + imgPath).c_str());
	if (Goblin::goblins.size() == 0) {
		Goblin::goblins.push_back(this);
	}
	SDL_Window* window = cwing::sys.get_win();
	int window_width, window_height;
	SDL_GetWindowSize(window, &window_width, &window_height);
	y_of_screen_bottom = window_height;
	x_of_screen_width = window_width;
}

Goblin::~Goblin() {}

void Goblin::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);
}

void Goblin::tick() {
	counter++;

	if ((rect.y + height >= y_of_screen_bottom) || isShot()) {
		ses.remove(this);
		auto it = std::find(Goblin::goblins.begin(), Goblin::goblins.end(), this); // Find the iterator pointing to the Goblin object
		if (it != goblins.end()) {
			Goblin::goblins.erase(it); // Remove the Goblin object from the goblins vector
		}
	}

	else if (counter % 100 == 0) {
		rect.y += 2;
		if (Goblin::goblins.size() < 7) {
			int x = rand() % (x_of_screen_width - width);
			Goblin* goblin = new Goblin(x, 50, 50);
			Goblin::goblins.push_back(goblin);
			ses.add(goblin);
			std::cout << Goblin::goblins.size() << std::endl;
		}
	}

}

bool Goblin::isShot() {
	for (Component* c : ses.getComps()) {
		// Skip this object
		if (c == this) continue;
		// Check if the two rectangles intersect
		SDL_Rect otherRect = c->getRect();
		if (SDL_HasIntersection(&rect, &otherRect)) {
			return true;
		}
	}
	return false;
}