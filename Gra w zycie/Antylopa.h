#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
public:
	Antylopa(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy);
};