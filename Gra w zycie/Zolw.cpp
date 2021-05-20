#include "Zolw.h"

Zolw::Zolw(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('Z');
	this->SetSila(2);
	this->SetZywy(true);
	this->SetInicjatywa(1);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Zolw::Kopiuj(int x, int y)
{
	return new Zolw(this->GetSwiat(), x, y);
}

void Zolw::akcja()
{
	int czySiePoruszam = (rand() % 100) + 1;

	if (czySiePoruszam > 75)
	{
		Zwierze::akcja();
	}
}

bool Zolw::czyOdbilAtak(Organizm* atakujacy)
{
	if (atakujacy->GetSila() < 5)
	{
		cout << this->GetNazwaGatunku() << " odbil atak ze strony " << atakujacy->GetNazwaGatunku() << endl;
		return true;
	}
	else
	{
		return false;
	}
}