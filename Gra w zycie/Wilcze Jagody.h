#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina
{
public:
	WilczeJagody(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
	void kolizja(Organizm* atakujacy) override;
};