#include "Guarana.h"

Guarana::Guarana(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('G');
	this->SetSila(0);
	this->SetZywy(true);
	this->SetInicjatywa(0);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Guarana::Kopiuj(int x, int y)
{
	return new Guarana(this->GetSwiat(), x, y);
}


void Guarana::kolizja(Organizm* atakujacy)
{
	cout << atakujacy->GetNazwaGatunku() << " zyskuje 3 punkty sily po zjedzeniu " << this->GetNazwaGatunku() << endl;
	atakujacy->SetSila(atakujacy->GetSila() + 3);
	Roslina::kolizja(atakujacy);
}