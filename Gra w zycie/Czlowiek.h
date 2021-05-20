#pragma once
#include "Zwierze.h"
#include <conio.h>

enum STRZALKI
{
	STRZALKA_DO_GORY = 72,
	STRZALKA_DO_DOLU = 80,
	STRZALKA_W_LEWO = 75,
	STRZALKA_W_PRAWO = 77,
};

class Czlowiek : public Zwierze
{
	int turaUmiejetnosci;
	int turaCooldownu;
public:
	Czlowiek(Swiat* _swiat,int x,int y,int umiejetnosc,int cooldown);
	void aktywujUmiejetnosc();
	void akcja() override;
	void kolizja(Organizm* kolidujacy) override;
	Organizm* Kopiuj(int x, int y) override;
	string ZapiszOrganizm() override;
	void SetTuraCd(int tura);
	void SetTuraUm(int tura);
};