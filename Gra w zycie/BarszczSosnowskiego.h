#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
	void kolizja(Organizm* atakujacy) override;
	void akcja() override;
	bool sprawdzCzyZwierze(int x, int y);
	void zabij(int x, int y);
};