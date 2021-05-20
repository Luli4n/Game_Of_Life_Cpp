#pragma once
#include "Organizm.h"
#define SZEROKOSC_RAMKI 1
#include <vector>
#include <algorithm>
#include <fstream>


using std::vector;

class Organizm;

class Swiat
{
private:
	int szerokosc;
	int wysokosc;
	int randX;
	int randY;
	int tura;
	Organizm*** Pola;

public:
	vector<Organizm*>Organizmy;
	
	Swiat(int x, int y);
	~Swiat();
	int GetSzerokosc();
	int GetWysokosc();
	int GetTura();

	Organizm* GetPole(int x, int y);
	void SetPole(Organizm* org, int x, int y);

	bool ZapiszSwiat(const std::string& sciezkaDoZapisu);
	bool ZaladujSwiat(const std::string& sciezkaDoPlikuZapisu);
	void nowaGra(int wysokosc, int szerokosc);

	void GenerujOrganizmy();
	void randomizeXandY();
	void wykonajTure();
	void rysujSwiat();
};

