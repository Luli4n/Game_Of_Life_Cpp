#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
public:
	Lis(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
	void akcja() override;
};