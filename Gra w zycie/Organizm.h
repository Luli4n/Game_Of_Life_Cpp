#pragma once
#include <iostream>
#include <string>
#include "Swiat.h"
using namespace std;

enum KIERUNEK
{
	LEWO,
	PRAWO,
	GORA,
	DOL,
	LEWO2X,
	PRAWO2X,
	GORA2X,
	DOL2X,
};

class Swiat;

class Organizm
{
private:
	int sila;
	int inicjatywa;
	int turaUrodzenia;
	int turaRozmnazania;
	int polozenieX;
	int polozenieY;
	char nazwaGatunku;
	bool zywy;
	Swiat* swiat;
public:
	
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* kolidujacy) = 0;
	virtual void rysowanie() = 0;
	virtual Organizm* Kopiuj(int x, int y) = 0;
	virtual bool sprawdzMiejsce();
	virtual bool czyOdbilAtak(Organizm* atakujacy) = 0;
	virtual string ZapiszOrganizm();

	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();

	void SetSila(int sila);
	void SetInicjatywa(int inicjatywa);
	void SetTuraUrodzenia(int tura);
	void SetSwiat(Swiat* _swiat);
	void SetZywy(bool czy);

	int GetSila() const;
	int GetInicjatywa() const;
	int GetTuraUrodzenia() const;
	Swiat* GetSwiat() ;
	bool GetZywy() const;

	int KiedySieRozmnozyl();
	void SetRozmnozylSie(int kiedy);
	

	char GetNazwaGatunku();
	void SetNazwaGatunku(char nazwa);

};