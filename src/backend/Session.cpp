#include "Component.h"
#include "Session.h"
#include "System.h"
#include <SDL2/SDL.h>

using namespace std;

#define FPS 60;

namespace cwing {

	void Session::add(Component* comp) {
		added.push_back(comp);
	}

	void Session::remove(Component* comp) {
		removed.push_back(comp);
	}

	void Session::run() {
		Uint32 tickInterval = 50 / FPS;

		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;

			while (SDL_PollEvent(&event)) {
				eventHandler(event);
			}

			for (Component* c : comps)
				c->tick();

			for (Component* c : added)
				comps.push_back(c);

			added.clear();

			for (Component* c : removed)
				for (auto i = comps.begin(); i != comps.end();)
					if (*i == c) {
						i = comps.erase(i);
					}
					else
						i++;
			removed.clear();

			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Component* c : comps)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		} // yttre while
	}

	void Session::eventHandler(SDL_Event const& event) {
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			for (Component* c : comps)
				c->mouseDown(event.button.x, event.button.y);
			break;
		case SDL_MOUSEBUTTONUP:
			for (Component* c : comps)
				c->mouseUp(event.button.x, event.button.y);
			break;
		} //switch


	}

	const std::vector<Component*>& Session::getComps() const {
		return comps;
	}


}
