#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze
{
public:
	Zolw(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
};