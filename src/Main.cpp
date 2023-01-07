
#include "Pistol.h"

cwing::Session ses;

int main(int argc, char** argv) {
	Pistol* pistol = new Pistol();
	ses.add(pistol);
	ses.run();

	return 0;
}





