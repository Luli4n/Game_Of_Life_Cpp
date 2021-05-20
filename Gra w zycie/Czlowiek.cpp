#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat* _swiat,int x,int y,int umiejetnosc,int cooldown)
{
	
	this->SetSwiat(_swiat);
	this->SetX(x);
	this->SetY(y);
	this->GetSwiat()->SetPole(this, x, y);
	this->SetTuraUrodzenia(this->GetSwiat()->GetTura());
	this->SetNazwaGatunku('C');
	this->SetSila(5);
	this->SetZywy(true);
	this->SetInicjatywa(4);
	this->turaCooldownu = cooldown;
	this->turaUmiejetnosci = umiejetnosc;
}


void Czlowiek::akcja()
{
	int aktualnyX = this->GetX();
	int aktualnyY = this->GetY();

	int nastepnyX;
	int nastepnyY;

	cout << "TuraUmiejetnosciCzlowieka:" << turaUmiejetnosci << endl;
	cout << "SilaCzlowieka:" << this->GetSila() << endl;
	
	if (turaUmiejetnosci > 0) {
		this->SetSila(this->GetSila() - 1);
	}

	if (turaCooldownu == 0 && turaUmiejetnosci==0) {
		cout << "Czy chcesz aktywowac umiejetnosc Magiczny Eliksir? (T/N)" << endl;
		char czyAkt=0;
		while (true) 
		{
			czyAkt = _getch();
			if (czyAkt == 'T')
			{
				this->aktywujUmiejetnosc();
				break;
			}
			else if (czyAkt == 'N')
			{
				break;
			}
		}
	}
	else
	{
		if (turaUmiejetnosci != 0) {
			--turaUmiejetnosci;
			cout << "Magiczny Eliksir bedzie jeszcze aktywny przez " << turaUmiejetnosci << " tur" << endl;
			++turaCooldownu;
		}
		else
		{
			--turaCooldownu;
			cout << "Magiczny Eliksir bedzie znowu gotowy do uzycia za " << turaCooldownu << " tur" << endl;
		}

	}

	cout << "Wykonaj ruch czlowieka" << endl;
	char ruch;
	bool poprawnosc_ruchu = false;
	while(poprawnosc_ruchu==false){
		ruch = _getch();
		switch (ruch) {
		case STRZALKA_DO_GORY:
		{
			if (aktualnyY != 0) {
				nastepnyY = aktualnyY - 1;
				nastepnyX = aktualnyX;
				poprawnosc_ruchu = true;
			}
			break;
		}
		case STRZALKA_DO_DOLU:
		{
			if (aktualnyY != GetSwiat()->GetWysokosc()-1) {
				nastepnyY = aktualnyY + 1;
				nastepnyX = aktualnyX;
				poprawnosc_ruchu = true;
			}
			break;
		}
		case STRZALKA_W_LEWO:
		{
			if (aktualnyX != 0) {
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX - 1;
				poprawnosc_ruchu = true;
			}
			break;
		}
		case STRZALKA_W_PRAWO:
		{
			if (aktualnyX != GetSwiat()->GetSzerokosc()-1) {
				nastepnyY = aktualnyY;
				nastepnyX = aktualnyX + 1;
				poprawnosc_ruchu = true;
			}
			break;
		}
		}
	}
	if (this->GetSwiat()->GetPole(nastepnyX,nastepnyY) != NULL) {
		this->kolizja(this->GetSwiat()->GetPole(nastepnyX,nastepnyY));
	}
	else
	{
		this->GetSwiat()->SetPole(NULL,this->GetX(),this->GetY());
		this->GetSwiat()->SetPole(this, nastepnyX, nastepnyY);
		this->SetX(nastepnyX);
		this->SetY(nastepnyY);
	}
}

void Czlowiek::aktywujUmiejetnosc()
{
	this->turaUmiejetnosci = 5;
	this->SetSila(this->GetSila() + turaUmiejetnosci);
}

void Czlowiek::kolizja(Organizm* kolidujacy)
{
	Zwierze::kolizja(kolidujacy);
}
Organizm* Czlowiek::Kopiuj(int x, int y)
{
	return new Czlowiek(this->GetSwiat(), x, y,0,0);
}

string Czlowiek::ZapiszOrganizm()
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
	organizm += ' ';
	organizm += to_string(this->turaUmiejetnosci);
	organizm += ' ';
	organizm += to_string(this->turaCooldownu);

	return organizm;
}

void Czlowiek::SetTuraCd(int tura)
{
	this->turaCooldownu = tura;
}

void Czlowiek::SetTuraUm(int tura)
{
	this->turaUmiejetnosci = tura;
}