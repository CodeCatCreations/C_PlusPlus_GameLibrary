#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>

//TODO: Sub-klasser till denna, Bullet + Pistol + Sprite


namespace cwing {
	class Component
	{
	public:
		virtual void mouseDown(int x, int y) {}
		virtual void mouseUp(int x, int y) {}
		virtual void draw() const = 0;
		SDL_Rect getRect() const { return rect; }
		// tick() varje sprite har en tick, som anropas en gång per varv i run loopen, tick består av beteendet av spriten
		// tex om en sprite rör sig uppdaterar tick dens x och y koordinater
		virtual void tick() = 0;
	protected:
		Component(int x, int y, int w, int h) : rect{ x,y,w,h } {}
		SDL_Rect rect;
	};

}

#endif
