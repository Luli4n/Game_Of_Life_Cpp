#include "Mlecz.h"

Mlecz::Mlecz(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('M');
	this->SetSila(0);
	this->SetZywy(true);
	this->SetInicjatywa(0);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Mlecz::Kopiuj(int x, int y)
{
	return new Mlecz(this->GetSwiat(), x, y);
}

void Mlecz::akcja()
{
	for (int i = 0; i < 3; i++) 
	{
		Roslina::akcja();
	}
}