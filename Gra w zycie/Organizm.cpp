#include "Organizm.h"


void Organizm::SetSila(int Sila)
{
	this->sila = Sila;
}

void Organizm::SetInicjatywa(int Inicjatywa)
{
	this->inicjatywa = Inicjatywa;
}

int Organizm::GetSila() const
{
	return this->sila;
}

int Organizm::GetInicjatywa() const
{
	return this->inicjatywa;
}

void Organizm::SetX(int x)
{
	this->polozenieX = x;
}

void Organizm::SetY(int y)
{
	this->polozenieY = y;
}

int Organizm::GetX()
{
	return this->polozenieX;
}

int Organizm::GetY()
{
	return this->polozenieY;
}

char Organizm::GetNazwaGatunku()
{
	return this->nazwaGatunku;
}

void Organizm::SetNazwaGatunku(char nazwa)
{
	this->nazwaGatunku = nazwa;
}

void Organizm::SetTuraUrodzenia(int tura)
{
	this->turaUrodzenia = tura;
}

int Organizm::GetTuraUrodzenia() const
{
	return this->turaUrodzenia;
}

void Organizm::SetSwiat(Swiat* _swiat)
{
	this->swiat = _swiat;
}

Swiat* Organizm::GetSwiat()
{
	return this->swiat;
}

void Organizm::SetZywy(bool czy)
{
	this->zywy = czy;
}

bool Organizm::GetZywy() const
{
	return this->zywy;
}

bool Organizm::sprawdzMiejsce()
{
	int ilosc_miejsc=0;
	int x = this->GetX();
	int y = this->GetY();

			if (y != 0)
			{
				if (this->GetSwiat()->GetPole(x,y-1) == NULL || this->GetSwiat()->GetPole(x, y - 1)->GetZywy()==false)
				{
					ilosc_miejsc++;
				}
			}
		
			if (y != this->GetSwiat()->GetWysokosc() - 1)
			{
				if (this->GetSwiat()->GetPole(x,y+1) == NULL || this->GetSwiat()->GetPole(x, y + 1)->GetZywy()==false)
				{
					ilosc_miejsc++;
				}

			}
	
			if (x != 0)
			{
				if (this->GetSwiat()->GetPole(x-1,y) == NULL || this->GetSwiat()->GetPole(x - 1, y)->GetZywy()==false)
				{
					ilosc_miejsc++;
				}
			}

			if (x!= this->GetSwiat()->GetSzerokosc() - 1)
			{
				if (this->GetSwiat()->GetPole(x+1,y) == NULL || this->GetSwiat()->GetPole(x + 1, y)->GetZywy()==false)
				{
					ilosc_miejsc++;
				}
			}
		
	if (ilosc_miejsc != 0)
	{
		return true;
	}
	return false;
}

int Organizm::KiedySieRozmnozyl()
{
	return turaRozmnazania;
}

void Organizm::SetRozmnozylSie(int kiedy)
{
	this->turaRozmnazania = kiedy;
}

string Organizm::ZapiszOrganizm()
{
	string organizm;
	organizm += to_string(this->GetNazwaGatunku()); 
	organizm += ' ';
	organizm += to_string(this->GetX());
	organizm += ' ';
	organizm += to_string(this->GetY());
	organizm += ' ';
	organizm += to_string(this->GetSila());
	organizm += ' ';
	organizm += to_string(this->GetInicjatywa());
	
	return organizm;
}