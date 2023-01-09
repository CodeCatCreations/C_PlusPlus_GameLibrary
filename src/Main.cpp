#include "Pistol.h"
#include "Goblin.h"
#include "SpaceShip.h"

cwing::Session ses;

int main(int argc, char** argv) {
	//Pistol* pistol = new Pistol();
	//ses.add(pistol);

	SpaceShip* ship = new SpaceShip();
	ses.add(ship);

	Goblin* goblin = new Goblin();
	//Goblin* goblin = new Goblin(0, 50, 50);
	ses.add(goblin);

	ses.run();

	return 0;
}





