#ifndef GOBLIN_H
#define GOBLIN_H

#include "Sprite.h"
#include <SDL2/SDL.h>

class Goblin: public Sprite {
public:
	Goblin(int x, int w, int h);
	~Goblin();
	void draw() const;
	void tick();
	bool isShot();

private:
	int width;
	int height;
	std::string imgPath = "images/goblin.svg";
	SDL_Texture* texture;
	int counter = 0;
	static std::vector<Goblin*> goblins;
	int y_of_screen_bottom;
	int x_of_screen_width;

};

#endif