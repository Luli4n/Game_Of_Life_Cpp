#include "Wilk.h"

Wilk::Wilk(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this,x,y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('W');
	this->SetSila(9);
	this->SetZywy(true);
	this->SetInicjatywa(5);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Wilk::Kopiuj(int x, int y)
{
	return new Wilk(this->GetSwiat(), x, y);
}