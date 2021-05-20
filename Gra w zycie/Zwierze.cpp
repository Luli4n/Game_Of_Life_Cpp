#include "Zwierze.h"

void Zwierze::akcja()
{
	int aktualnyX=this->GetX();
	int aktualnyY=this->GetY();
	int nastepnyX;
	int nastepnyY;

	int ruch;
	bool powodzenieRuchu = false;
	while (powodzenieRuchu == false)
	{
		ruch = rand() % 4;
		switch (ruch)
		{
		case GORA:
			if (aktualnyY != 0)
			{
				nastepnyY=aktualnyY - 1;
				nastepnyX=aktualnyX;
				powodzenieRuchu = true;
			}
			break;
		case DOL:
			if (aktualnyY != this->GetSwiat()->GetWysokosc()-1)
			{
				nastepnyY=aktualnyY + 1;
				nastepnyX = aktualnyX;
				powodzenieRuchu = true;
			}
			break;
		case LEWO:
			if (aktualnyX != 0)
			{
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX-1;
				powodzenieRuchu = true;
			}
			break;
		case PRAWO:
			if (aktualnyX != this->GetSwiat()->GetSzerokosc()-1)
			{
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX + 1;
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
		this->GetSwiat()->SetPole(NULL, aktualnyX, aktualnyY);
		this->GetSwiat()->SetPole(this, nastepnyX, nastepnyY);
		this->SetX(nastepnyX);
		this->SetY(nastepnyY);
	}
	
}


void Zwierze::kolizja(Organizm* kolidujacy)
{
	
		char GatunekOrganizmu = this->GetNazwaGatunku();
		char GatunekKolidujacego = kolidujacy->GetNazwaGatunku();
	
		if (GatunekOrganizmu == GatunekKolidujacego)
		{
			rozmnazaj(kolidujacy);
		}
		else if (kolidujacy->czyOdbilAtak(this) == false)
		{
		
				this->GetSwiat()->SetPole(NULL, this->GetX(), this->GetY());
				if (this->GetSila() >= kolidujacy->GetSila())
				{
					cout << this->GetNazwaGatunku() << " zabija " << kolidujacy->GetNazwaGatunku() << " po ataku ze strony " << this->GetNazwaGatunku() << endl;
					vector<Organizm*>::iterator it = std::find(this->GetSwiat()->Organizmy.begin(), this->GetSwiat()->Organizmy.end(), kolidujacy);
					int index = std::distance(this->GetSwiat()->Organizmy.begin(), it);
					this->GetSwiat()->SetPole(this, kolidujacy->GetX(), kolidujacy->GetY());
					this->SetX(kolidujacy->GetX());
					this->SetY(kolidujacy->GetY());
					this->GetSwiat()->Organizmy[index]->SetZywy(false);


				}
				else
				{
					cout << kolidujacy->GetNazwaGatunku() << " zabija " << this->GetNazwaGatunku() << " po ataku ze strony " << this->GetNazwaGatunku() << endl;
					vector<Organizm*>::iterator it = std::find(this->GetSwiat()->Organizmy.begin(), this->GetSwiat()->Organizmy.end(), this);
					int index = std::distance(this->GetSwiat()->Organizmy.begin(), it);
					this->GetSwiat()->Organizmy[index]->SetZywy(false);
				}

		}
}

void Zwierze::rysowanie()
{
	cout << " " << this->GetNazwaGatunku()<< " ";
}

void Zwierze::rozmnazaj(Organizm* kolidujacy)
{
	if (this->KiedySieRozmnozyl() != this->GetSwiat()->GetTura() && kolidujacy->KiedySieRozmnozyl() != this->GetSwiat()->GetTura()) {
		bool flaga_miejsce1 = false;
		bool flaga_miejsce2 = false;
		int Wybor_Organizmu;

		if (this->sprawdzMiejsce() == true)
		{
			flaga_miejsce1 = true;
			Wybor_Organizmu = 0;
		}
		if (kolidujacy->sprawdzMiejsce() == true)
		{
			flaga_miejsce2 = true;
			Wybor_Organizmu = 1;
		}

		if (flaga_miejsce1 == true && flaga_miejsce2 == true) {
			Wybor_Organizmu = rand() % 2;
		}

		if (flaga_miejsce1 == true || flaga_miejsce2 == true) {
			int nowyX;
			int nowyY;

			int randX = rand() % 3;
			int randY = rand() % 3;
			bool flaga = false;
			if (Wybor_Organizmu == 0)
			{
				nowyX = this->GetX();
				nowyY = this->GetY();
			}
			else
			{
				nowyX = kolidujacy->GetX();
				nowyY = kolidujacy->GetY();
			}

			while (true)
			{
				if ((nowyY - 1 + randY) >= 0 && (nowyY - 1 + randY) <= (this->GetSwiat()->GetWysokosc() - 1)
					&& (nowyX - 1 + randX) >= 0 && (nowyX - 1 + randX) <= (this->GetSwiat()->GetSzerokosc() - 1))
				{
					flaga = true;
				}
				if (flaga == true) {
					if (this->GetSwiat()->GetPole(nowyX - 1 + randX,nowyY - 1 + randY) == NULL)
					{
						flaga = true;
						break;
					}
					flaga = false;
				}
				randX = rand() % 3;
				randY = rand() % 3;

			}
			Organizm* noweZycie = Kopiuj(nowyX - 1 + randX, nowyY - 1 + randY);
			this->GetSwiat()->Organizmy.push_back(noweZycie);
			cout << noweZycie->GetNazwaGatunku() << " sie narodzil" << endl;
			this->SetRozmnozylSie(this->GetSwiat()->GetTura());
			kolidujacy->SetRozmnozylSie(kolidujacy->GetSwiat()->GetTura());

		}
	}
}

bool Zwierze::czyOdbilAtak(Organizm* atakujacy)
{
	return false;
}