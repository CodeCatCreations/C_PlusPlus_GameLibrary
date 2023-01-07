/* #include "Button.h"
#include "Constants.h"
#include "System.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace cwing {

	Button::Button(int x, int y, int w, int h, std::string txt): Component(x, y, w, h) {
		SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0, 0, 0 });
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
		SDL_FreeSurface(surf);
		upIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/UppKnapp.png").c_str());
		downIcon = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/NerKnapp.png").c_str());
	}

	Button::~Button() {
		SDL_DestroyTexture(texture);
		SDL_DestroyTexture(upIcon);
		SDL_DestroyTexture(downIcon);
	}

	Button* Button::getInstance(int x, int y, int w, int h, std::string txt) {
		return new Button(x, y, w, h, txt);
	}

	void Button::mouseDown(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		SDL_Rect rect = getRect();
		if (SDL_PointInRect(&p, &rect))
			isDown = true;
	}
	void Button::mouseUp(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		SDL_Rect rect = getRect();
		if (SDL_PointInRect(&p, &rect))
			perform(this);

		isDown = false;
	}
	void Button::draw() const {
		if (isDown) {
			SDL_Rect rect = getRect();
			SDL_RenderCopy(sys.get_ren(), downIcon, NULL, &rect);
		}
		else {
			SDL_RenderCopy(sys.get_ren(), upIcon, NULL, &rect);
		}
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
	}
} */