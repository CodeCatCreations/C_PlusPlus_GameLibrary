#ifndef GOBLIN_H
#define GOBLIN_H

#include "Sprite.h"
#include <SDL2/SDL.h>
#include "Component.h"

class Goblin: public Sprite {
public:
	Goblin(int x, int w, int h);
	Goblin(): Goblin(0, 50, 50) {};
	~Goblin();
	void draw() const;
	void tick();
	bool isShot();
	bool intersects(const SDL_Rect& otherRect) const override;

private:
	int width;
	int height;
	std::string imgPath = "images/goblin.svg";
	SDL_Texture* texture;
	int counter = 0;
	static std::vector<Goblin*> goblins;
	int y_of_screen_bottom;
	int x_of_screen_width;
	bool is_shot = false;

};

#endif