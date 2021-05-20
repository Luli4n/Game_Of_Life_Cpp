#include "Antylopa.h"

Antylopa::Antylopa(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('A');
	this->SetSila(4);
	this->SetZywy(true);
	this->SetInicjatywa(4);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Antylopa::Kopiuj(int x, int y)
{
	return new Antylopa(this->GetSwiat(), x, y);
}

void Antylopa::akcja()
{
	int aktualnyX = this->GetX();
	int aktualnyY = this->GetY();
	int nastepnyX;
	int nastepnyY;

	int ruch;
	bool powodzenieRuchu = false;
	while (powodzenieRuchu == false)
	{
		ruch = rand() % 8;
		switch (ruch)
		{
		case GORA:
			if (aktualnyY != 0)
			{
				nastepnyY = aktualnyY - 1;
				nastepnyX = aktualnyX;
				powodzenieRuchu = true;
			}
			break;
		case DOL:
			if (aktualnyY != this->GetSwiat()->GetWysokosc() - 1)
			{
				nastepnyY = aktualnyY + 1;
				nastepnyX = aktualnyX;
				powodzenieRuchu = true;
			}
			break;
		case LEWO:
			if (aktualnyX != 0)
			{
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX - 1;
				powodzenieRuchu = true;
			}
			break;
		case PRAWO:
			if (aktualnyX != this->GetSwiat()->GetSzerokosc() - 1)
			{
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX + 1;
				powodzenieRuchu = true;
			}
			break;
		case GORA2X:
			if (aktualnyY > 1)
			{
				nastepnyY = aktualnyY - 2;
				nastepnyX = aktualnyX;
				powodzenieRuchu = true;
			}
			break;
		case DOL2X:
			if (aktualnyY < this->GetSwiat()->GetWysokosc() - 2)
			{
				nastepnyY = aktualnyY + 2;
				nastepnyX = aktualnyX;
				powodzenieRuchu = true;
			}
			break;
		case LEWO2X:
			if (aktualnyX > 1)
			{
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX - 2;
				powodzenieRuchu = true;
			}
			break;
		case PRAWO2X:
			if (aktualnyX < this->GetSwiat()->GetSzerokosc() - 2)
			{
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX + 2;
				powodzenieRuchu = true;
			}
			break;
		}
	}

	if (this->GetSwiat()->GetPole(nastepnyX, nastepnyY) != NULL) {
		this->kolizja(this->GetSwiat()->GetPole(nastepnyX, nastepnyY));
	}
	else
	{
		this->GetSwiat()->SetPole(NULL, this->GetX(), this->GetY());
		this->GetSwiat()->SetPole(this, nastepnyX, nastepnyY);
		this->SetX(nastepnyX);
		this->SetY(nastepnyY);
	}
}

bool Antylopa::czyOdbilAtak(Organizm* atakujacy)
{
	int random = rand() % 100 + 1;

	if (random < 50)
	{
		int aktualnyX = this->GetX();
		int aktualnyY = this->GetY();
		int nastepnyX = aktualnyX;
		int nastepnyY = aktualnyY;

		int ruch;
		bool powodzenieRuchu = false;
		bool sprawdzenieStron[4] = { false,false,false,false };

		while (powodzenieRuchu == false)
		{
			ruch = rand() % 4;
			switch (ruch)
			{
			case GORA:
				if (aktualnyY != 0)
				{
					nastepnyY = aktualnyY - 1;
					nastepnyX = aktualnyX;

				}
				sprawdzenieStron[0] = true;
				break;
			case DOL:
				if (aktualnyY != this->GetSwiat()->GetWysokosc() - 1)
				{
					nastepnyY = aktualnyY + 1;
					nastepnyX = aktualnyX;

				}
				sprawdzenieStron[1] = true;
				break;
			case LEWO:
				if (aktualnyX != 0)
				{
					nastepnyY = aktualnyY;
					nastepnyX = aktualnyX - 1;

				}
				sprawdzenieStron[2] = true;
				break;
			case PRAWO:
				if (aktualnyX != this->GetSwiat()->GetSzerokosc() - 1)
				{
					nastepnyY = aktualnyY;
					nastepnyX = aktualnyX + 1;

				}
				sprawdzenieStron[3] = true;
				break;
			}
			if (this->GetSwiat()->GetPole(nastepnyX, nastepnyY) == NULL)
			{
				powodzenieRuchu = true;
			}

			if (sprawdzenieStron[0] == true && sprawdzenieStron[1] == true && sprawdzenieStron[2] == true && sprawdzenieStron[3] == true
				&& powodzenieRuchu == false)
			{
				return false;
			}
		}

		cout << this->GetNazwaGatunku() << " uciekla przed " << atakujacy->GetNazwaGatunku() << endl;


		this->GetSwiat()->SetPole(NULL, atakujacy->GetX(), atakujacy->GetY());
		this->SetX(nastepnyX);
		this->SetY(nastepnyY);
		this->GetSwiat()->SetPole(this, nastepnyX, nastepnyY);
		atakujacy->SetX(aktualnyX);
		atakujacy->SetY(aktualnyY);
		atakujacy->GetSwiat()->SetPole(atakujacy, aktualnyX, aktualnyY);
		
		return true;
	}
	else
	{
		return false;
	}
}