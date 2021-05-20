#include "BarszczSosnowskiego.h"
BarszczSosnowskiego::BarszczSosnowskiego(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('B');
	this->SetSila(10);
	this->SetZywy(true);
	this->SetInicjatywa(0);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* BarszczSosnowskiego::Kopiuj(int x, int y)
{
	return new BarszczSosnowskiego(this->GetSwiat(), x, y);
}

void BarszczSosnowskiego::akcja()
{

	int aktualnyX = this->GetX();
	int aktualnyY = this->GetY();
		
	if (aktualnyY != 0)
	{
		if (sprawdzCzyZwierze(aktualnyX, aktualnyY - 1) == true)
		{
			zabij(aktualnyX, aktualnyY - 1);
		}
	}
		
	if (aktualnyY != this->GetSwiat()->GetWysokosc() - 1)
	{
		if (sprawdzCzyZwierze(aktualnyX, aktualnyY + 1) == true)
		{
			zabij(aktualnyX, aktualnyY + 1);
		}
	}

	if (aktualnyX != 0)
	{
		if (sprawdzCzyZwierze(aktualnyX-1, aktualnyY) == true)
		{
			zabij(aktualnyX-1, aktualnyY);
		}
	}

	if (aktualnyX != this->GetSwiat()->GetSzerokosc() - 1)
	{
		if (sprawdzCzyZwierze(aktualnyX+1, aktualnyY) == true)
		{
			zabij(aktualnyX+1, aktualnyY);
		}
	}

	Roslina::akcja();
}

bool BarszczSosnowskiego::sprawdzCzyZwierze(int x, int y)
{
	if (this->GetSwiat()->GetPole(x, y) != NULL) {
		char klasaOrganizmu = this->GetSwiat()->GetPole(x, y)->GetNazwaGatunku();
		if (klasaOrganizmu == 'G' || klasaOrganizmu == 'M' || klasaOrganizmu == 'J' || klasaOrganizmu == 'T' || klasaOrganizmu=='B')
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void BarszczSosnowskiego::zabij(int x, int y)
{
	Organizm* organizm = this->GetSwiat()->GetPole(x, y);

	cout << this->GetNazwaGatunku() << " zabija zwierze w swoim sasiedztwie" << endl;
	vector<Organizm*>::iterator it = std::find(this->GetSwiat()->Organizmy.begin(), this->GetSwiat()->Organizmy.end(), organizm);
	int index = std::distance(this->GetSwiat()->Organizmy.begin(), it);
	this->GetSwiat()->SetPole(NULL, organizm->GetX(), organizm->GetY());
	this->GetSwiat()->Organizmy[index]->SetZywy(false);
}

void BarszczSosnowskiego::kolizja(Organizm* atakujacy)
{
	cout << atakujacy->GetNazwaGatunku() << " zjadl " << this->GetNazwaGatunku() << " i zginal" << endl;
	vector<Organizm*>::iterator it = std::find(this->GetSwiat()->Organizmy.begin(), this->GetSwiat()->Organizmy.end(), atakujacy);
	int index = std::distance(this->GetSwiat()->Organizmy.begin(), it);
	this->GetSwiat()->SetPole(NULL, atakujacy->GetX(), atakujacy->GetY());
	this->GetSwiat()->Organizmy[index]->SetZywy(false);
}