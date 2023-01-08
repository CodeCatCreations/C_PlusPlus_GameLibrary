#include "Pistol.h"

Pistol::Pistol(): Component(0, 0, 0, 0) {}

void Pistol::draw() const {}

void Pistol::tick() {}

void Pistol::mouseDown(int x, int y) {
    Bullet* b = Bullet::getInstance(x, y);
    cwing::ses.add(b);
}

void Pistol::mouseUp(int x, int y) {}
