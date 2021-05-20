#include "Wilcze Jagody.h"
WilczeJagody::WilczeJagody(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('J');
	this->SetSila(99);
	this->SetZywy(true);
	this->SetInicjatywa(0);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* WilczeJagody::Kopiuj(int x, int y)
{
	return new WilczeJagody(this->GetSwiat(), x, y);
}

void WilczeJagody::kolizja(Organizm* atakujacy)
{
	cout << atakujacy->GetNazwaGatunku() << " zjadl " << this->GetNazwaGatunku() << " i zginal"<< endl;
	vector<Organizm*>::iterator it = std::find(this->GetSwiat()->Organizmy.begin(), this->GetSwiat()->Organizmy.end(), atakujacy);
	int index = std::distance(this->GetSwiat()->Organizmy.begin(), it);
	this->GetSwiat()->SetPole(NULL, atakujacy->GetX(), atakujacy->GetY());
	this->GetSwiat()->Organizmy[index]->SetZywy(false);
}