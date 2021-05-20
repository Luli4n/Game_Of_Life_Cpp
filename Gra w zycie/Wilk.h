#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
public:
	Wilk(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x,int y) override;
};