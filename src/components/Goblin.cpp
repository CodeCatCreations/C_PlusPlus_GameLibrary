#include "Constants.h"
#include "Goblin.h"
#include "Sprite.h"
#include "Bullet.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include <iostream>

std::vector<Goblin*> Goblin::goblins;

Goblin::Goblin(int x, int w, int h): Sprite(x, 0, w, h), width(w), height(h) {
	texture = IMG_LoadTexture(cwing::sys.get_ren(), (constants::gResPath + imgPath).c_str());
	if (Goblin::goblins.size() == 0) {
		Goblin::goblins.push_back(this);
	}
	x_of_screen_width = cwing::sys.getWindowWidth();
	y_of_screen_bottom = cwing::sys.getWindowHeight();
}

Goblin::~Goblin() {}

void Goblin::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(cwing::sys.get_ren(), texture, NULL, &rect);
}

void Goblin::tick() {
	counter++;

	if ((rect.y + height >= y_of_screen_bottom)) {
		ses.remove(this);
		auto it = std::find(Goblin::goblins.begin(), Goblin::goblins.end(), this); // Find the iterator pointing to the Goblin object
		if (it != goblins.end()) {
			Goblin::goblins.erase(it); // Remove the Goblin object from the goblins vector
		}
	}

	else if (counter % 100 == 0) {
		rect.y += 2;
		if (Goblin::goblins.size() < 7 && counter % 500 == 0) {
			int x = rand() % (x_of_screen_width - width);
			Goblin* goblin = new Goblin(x, 50, 50);
			bool intersects = false;
			for (Goblin* g : Goblin::goblins) {
				if (goblin->intersects(g->getRect())) {
					intersects = true;
					break;
				}
			}
			if (!intersects) {
				Goblin::goblins.push_back(goblin);
				ses.add(goblin);
			}

		}
	}

}

bool Goblin::isShot() {
	for (Component* c : ses.getComps()) {
		// Skip this object
		if (c == this) continue;
		if (dynamic_cast<Goblin*>(c)) continue;
		// Check if the two rectangles intersect
		if (intersects(c->getRect())) {
			return true;
		}
	}
	return false;
}

bool Goblin::intersects(const SDL_Rect& otherRect) const {
	// Store the result of getRect in a local variable
	SDL_Rect rect = getRect();
	// Check if the Bullet and otherRect rectangles intersect
	if (SDL_HasIntersection(&rect, &otherRect)) {

		// Find the iterator pointing to the Goblin object
		auto it = std::find(Goblin::goblins.begin(), Goblin::goblins.end(), this);
		if (it != goblins.end()) {
			Goblin::goblins.erase(it); // Remove the Goblin object from the goblins vector
		}

		return true;
	}
	return false;
}




