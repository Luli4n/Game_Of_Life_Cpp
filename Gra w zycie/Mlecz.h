#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
public:
	Mlecz(Swiat* _swiat, int x, int y);
	void akcja() override;
	Organizm* Kopiuj(int x, int y) override;
};