#pragma once
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	void akcja() override;
	void kolizja(Organizm* atakujacy) override;
	void rysowanie();
	virtual Organizm* Kopiuj(int x, int y) = 0;
	bool czyOdbilAtak(Organizm* atakujacy) override;
};