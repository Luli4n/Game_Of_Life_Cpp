#include "Trawa.h"

Trawa::Trawa(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('T');
	this->SetSila(0);
	this->SetZywy(true);
	this->SetInicjatywa(0);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Trawa::Kopiuj(int x, int y)
{
	return new Trawa(this->GetSwiat(), x, y);
}