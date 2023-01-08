
#include "GameEngine.h"
#include "Pistol.h"
#include "sprites/Goblin.h"

namespace cwing {
	Session ses; // Statisk global Session-objekt
	System sys; // Statisk global System-objekt
}

int main(int argc, char** argv) {
	Pistol* pistol = new Pistol();
	cwing::ses.add(pistol);

	Goblin* goblin = new Goblin(0, 50, 50);
	cwing::ses.add(goblin);

	cwing::ses.run();

	return 0;
}





