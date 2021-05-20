#include "Roslina.h"

void Roslina::akcja()
{
	int prawdopodobienstwo = rand() % 100;

	if (prawdopodobienstwo < 5)
	{
		int aktualnyX = this->GetX();
		int aktualnyY = this->GetY();
		int nowyX=aktualnyX;
		int nowyY=aktualnyY;

		int rozprz;
		bool powodzenieRozprz = false;
		bool sprawdzenieStron[4] = { false,false,false,false };

		while (powodzenieRozprz == false)
		{
			rozprz = rand() % 4;
			switch (rozprz)
			{
			case GORA:
				if (aktualnyY != 0)
				{
					nowyY = aktualnyY - 1;
					nowyX = aktualnyX;

				}
				sprawdzenieStron[0] = true;
				break;
			case DOL:
				if (aktualnyY != this->GetSwiat()->GetWysokosc() - 1)
				{
					nowyY = aktualnyY + 1;
					nowyX = aktualnyX;

				}
				sprawdzenieStron[1] = true;
				break;
			case LEWO:
				if (aktualnyX != 0)
				{
					nowyY = aktualnyY;
					nowyX = aktualnyX - 1;

				}
				sprawdzenieStron[2] = true;
				break;
			case PRAWO:
				if (aktualnyX != this->GetSwiat()->GetSzerokosc() - 1)
				{
					nowyY = aktualnyY;
					nowyX = aktualnyX + 1;

				}
				sprawdzenieStron[3] = true;
				break;
			}
			if (this->GetSwiat()->GetPole(nowyX, nowyY) == NULL)
			{
				powodzenieRozprz = true;
			}

			if (sprawdzenieStron[0] == true && sprawdzenieStron[1] == true && sprawdzenieStron[2] == true && sprawdzenieStron[3] == true
				&& powodzenieRozprz == false)
			{
				break;
			}
		}

		if (powodzenieRozprz == true)
		{
			Organizm* nowy=this->Kopiuj(nowyX, nowyY);
			this->GetSwiat()->Organizmy.push_back(nowy);
		}

	}
}

bool Roslina::czyOdbilAtak(Organizm* atakujacy)
{
	this->kolizja(atakujacy);
	return true;
}

void Roslina::kolizja(Organizm* atakujacy)
{
	this->GetSwiat()->SetPole(NULL, atakujacy->GetX(), atakujacy->GetY());
	cout << atakujacy->GetNazwaGatunku() << " zjada " << this->GetNazwaGatunku() << endl;
	vector<Organizm*>::iterator it = std::find(this->GetSwiat()->Organizmy.begin(), this->GetSwiat()->Organizmy.end(), this);
	int index = std::distance(this->GetSwiat()->Organizmy.begin(), it);
	this->GetSwiat()->SetPole(atakujacy, this->GetX(), this->GetY());
	atakujacy->SetX(this->GetX());
	atakujacy->SetY(this->GetY());
	this->GetSwiat()->Organizmy[index]->SetZywy(false);
}


void Roslina::rysowanie()
{
	cout << " " << this->GetNazwaGatunku() << " ";
}