#pragma once
#include "Zwierze.h"

class Owca : public Zwierze
{
public:
	Owca(Swiat* _swiat, int x, int y);
	Organizm* Kopiuj(int x, int y) override;
};