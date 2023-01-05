#ifndef SESSION_H
#define SESSION_H

#include "Component.h"
#include <vector>

namespace cwing {
	class Session
	{
	public:
		Session(){};
		void add(Component* comp);
		void remove(Component* comp);
		void run(); // För varje varv i loopen går man igenom alla komponenter (sprite) och anropar tick()
	private:
		std::vector<Component*> comps; // sprites ska läggas till
		std::vector<Component*> added, removed;
	};

}
#endif