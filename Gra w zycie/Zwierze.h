#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	void akcja() override;
	void kolizja(Organizm* kolidujacy) override;
	void rysowanie();
	void rozmnazaj(Organizm* kolidujacy);
	virtual Organizm* Kopiuj(int x, int y) = 0;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	
};