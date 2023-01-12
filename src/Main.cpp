#include "Pistol.h"
#include "Goblin.h"
#include "SpaceShip.h"

cwing::Session ses;

int main(int argc, char** argv) {

	SpaceShip* ship = new SpaceShip();
	ses.add(ship);

	Goblin* goblin = new Goblin();
	ses.add(goblin);

	ses.run();

	return 0;
}





