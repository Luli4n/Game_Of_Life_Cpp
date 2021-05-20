#include "Lis.h"

Lis::Lis(Swiat* _swiat, int x, int y)
{
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('L');
	this->SetSila(3);
	this->SetZywy(true);
	this->SetInicjatywa(7);
	this->SetRozmnozylSie(this->GetSwiat()->GetTura());
}

Organizm* Lis::Kopiuj(int x, int y)
{
	return new Lis(this->GetSwiat(), x, y);
}

void Lis::akcja()
{
	int aktualnyX = this->GetX();
	int aktualnyY = this->GetY();
	int nastepnyX=aktualnyX;
	int nastepnyY=aktualnyY;

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
		if (this->GetSwiat()->GetPole(nastepnyX, nastepnyY) == NULL || this->GetSwiat()->GetPole(nastepnyX, nastepnyY)->GetSila() < this->GetSila())
		{
			powodzenieRuchu = true;
		}

		if (sprawdzenieStron[0] == true && sprawdzenieStron[1] == true && sprawdzenieStron[2] == true && sprawdzenieStron[3] == true && powodzenieRuchu == false)
		{
			powodzenieRuchu = true;
			nastepnyY = aktualnyY;
			nastepnyX = aktualnyX;
		}
	}

	if (nastepnyY == aktualnyY && nastepnyX == aktualnyX) {
		cout << this->GetNazwaGatunku() << " pozostaje na pozycji" << endl;
	}
	else if (this->GetSwiat()->GetPole(nastepnyX, nastepnyY) != NULL) {
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