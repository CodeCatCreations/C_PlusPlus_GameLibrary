
#include "GameEngine.h"
#include "Pistol.h"
#include "Goblin.h"

cwing::Session ses;

int main(int argc, char** argv) {
	Pistol* pistol = new Pistol();
	ses.add(pistol);

	Goblin* goblin = new Goblin();
	//Goblin* goblin = new Goblin(0, 50, 50);
	ses.add(goblin);

	ses.run();

	return 0;
}





