#pragma once
#include "Roslina.h"

class Trawa : public Roslina
{
public:
	Trawa(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
};