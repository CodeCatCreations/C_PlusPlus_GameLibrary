#ifndef SESSION_H
#define SESSION_H

#include "Component.h"
#include <vector>

namespace cwing {

	class Session {
	public:
		Session() {};
		void add(Component* comp);
		void remove(Component* comp);
		const std::vector<Component*>& getComps() const;
		void run();
	private:
		std::vector<Component*> comps;
		std::vector<Component*> added, removed;
		void eventHandler(SDL_Event const& event);
		bool quit = false;
		void checkIntersections();
	};

}
#endif