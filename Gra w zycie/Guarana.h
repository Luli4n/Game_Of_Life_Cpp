#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
	void kolizja(Organizm* atakujacy) override;
};