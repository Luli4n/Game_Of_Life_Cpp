#include "Owca.h"

Owca::Owca(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('O');
	this->SetSila(4);
	this->SetZywy(true);
	this->SetInicjatywa(4);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Owca::Kopiuj(int x, int y)
{
	return new Owca(this->GetSwiat(), x, y);
}