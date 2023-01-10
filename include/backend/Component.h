#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>

// TODO: Sub-klasser till denna, Bullet + Pistol + Sprite

namespace cwing {

	class Component {
	public:
		virtual void mouseDown(int x, int y) {}
		virtual void mouseUp(int x, int y) {}
		virtual void keyDown() {}
		virtual void keyUp() {}
		virtual void keyLeft() {}
		virtual void keyRight() {}
		virtual void draw() const = 0;
		SDL_Rect getRect() const { return rect; }
		virtual void tick() = 0;
		virtual ~Component() = default;
		virtual bool intersects(const SDL_Rect& otherRect) const {
			return SDL_HasIntersection(&rect, &otherRect);
		}

	protected:
		Component(int x, int y, int w, int h): rect{ x, y, w, h } {}
		SDL_Rect rect;
	};

}

#endif
