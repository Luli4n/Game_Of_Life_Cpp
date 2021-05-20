#include <iostream>
#include "Swiat.h"
#include "WszystkieOrganizmy.h"

using namespace std;

Swiat::Swiat(int x, int y) :szerokosc{ x }, wysokosc{ y }
{
	Pola = new Organizm**[y];

	for (int i = 0; i < y; i++)
	{
		Pola[i] = new Organizm*[x];
	}

	for (int m = 0; m < y; m++)
	{
		for (int n = 0; n < x; n++)
		{
			Pola[m][n] = NULL;
		}
	}
	randX = rand() % wysokosc;
	randY = rand() % szerokosc;
	tura = 0;
}

Swiat::~Swiat()
{
	for (int m = 0; m < wysokosc; m++)
	{
		delete[] Pola[m];
	}
	delete[] Pola;
}

void Swiat::rysujSwiat()
{
	
	GenerujOrganizmy();
	char nastTura;
	bool flaga = false;
	while (true){	

	cout << "Julian Krabel 180336" << endl << endl;
	
	for (int i = 0; i < wysokosc + 2; i++)
	{
		for (int j = 0; j < szerokosc + 2; j++)
		{
			if (i == 0 || j == 0 || i == wysokosc + 1 || j == szerokosc + 1)
			{
				cout << " # ";
			}
			else if (Pola[i - SZEROKOSC_RAMKI][j - SZEROKOSC_RAMKI] == NULL)
			{
				cout << "   ";
			}
			else
			{
				Pola[i - SZEROKOSC_RAMKI][j - SZEROKOSC_RAMKI]->rysowanie();
			}
		}
		cout << endl;
	}
	if (flaga == true)
	{
		this->wykonajTure();
		this->tura++;
	}
	cout << "Wcisnij T, aby przejsc do nastepnej tury" << endl;
	cout << "Wcisnij S, aby zapisac lub L aby zaladowac" << endl;
	while (true) {
		nastTura = _getch();
		if (nastTura == 'T')
		{
			system("cls");
			flaga = true;
			break;
		}
		if (nastTura == 'S')
		{
			string nazwa;
			cout << "Podaj nazwe zapisu:";
			cin >> nazwa;
			ZapiszSwiat(nazwa);
		}
		if (nastTura == 'L')
		{
			string nazwa;
			cout << "Podaj nazwe zapisu do wczytania:";
			cin >> nazwa;
			ZaladujSwiat(nazwa);
		}
	}
}
}

void Swiat::wykonajTure()
{
	std::sort(this->Organizmy.begin(), this->Organizmy.end(), [](const Organizm* e1, const  Organizm* e2)
		{
			if (e1->GetInicjatywa() != e2->GetInicjatywa())
			{
				return (e1->GetInicjatywa() > e2->GetInicjatywa());
			}
			return (e1->GetTuraUrodzenia() < e2->GetTuraUrodzenia());
		});

	

	for (int i=0;i<Organizmy.size();i++)
	{
		if (Organizmy[i]->GetZywy() ==true && Organizmy[i]->GetTuraUrodzenia() != this->GetTura())
		{
			Organizmy[i]->akcja();
		}
		
	}	

	for (int i = Organizmy.size() - 1; i >= 0; i--) {
		if (Organizmy[i]->GetZywy()==false) {
			delete Organizmy[i];
			Organizmy.erase(Organizmy.begin() + i);
		}
	}
	
	
}

int Swiat::GetSzerokosc()
{
	return this->szerokosc;
}

int Swiat::GetWysokosc()
{
	return this->wysokosc;
}

void Swiat::GenerujOrganizmy()
{

	randomizeXandY();
	if (ILOSC_LUDZI != 0) {
		Organizmy.push_back(new Czlowiek(this, randX, randY,0,0));
	}

	for (int w = 0; w < ILOSC_WILKOW; w++)
	{
		randomizeXandY();
		Organizmy.push_back(new Wilk(this, randX, randY));
	}

	for (int o = 0; o < ILOSC_OWIEC; o++)
	{
		randomizeXandY();
		Organizmy.push_back(new Owca(this, randX, randY));
	}

	for (int l = 0; l < ILOSC_LISOW; l++)
	{
		randomizeXandY();
		Organizmy.push_back(new Lis(this, randX, randY));
	}
	
	for (int z = 0; z < ILOSC_ZOLWIOW; z++)
	{
		randomizeXandY();
		Organizmy.push_back(new Zolw(this, randX, randY));
	}

	for (int a = 0; a < ILOSC_ANTYLOP; a++)
	{
		randomizeXandY();
		Organizmy.push_back(new Antylopa(this, randX, randY));
	}

	for (int t = 0; t < ILOSC_TRAW; t++)
	{
		randomizeXandY();
		Organizmy.push_back(new Trawa(this, randX, randY));
	}

	for (int m = 0; m < ILOSC_MLECZY; m++)
	{
		randomizeXandY();
		Organizmy.push_back(new Mlecz(this, randX, randY));
	}

	for (int g = 0; g < ILOSC_GUARAN; g++)
	{
		randomizeXandY();
		Organizmy.push_back(new Guarana(this, randX, randY));
	}

	for (int j = 0; j < ILOSC_WILCZYCH_JAGOD; j++)
	{
		randomizeXandY();
		Organizmy.push_back(new WilczeJagody(this, randX, randY));
	}

	for (int s = 0; s < ILOSC_BARSZCZU; s++)
	{
		randomizeXandY();
		Organizmy.push_back(new BarszczSosnowskiego(this, randX, randY));
	}
}

void Swiat::randomizeXandY()
{
	while (Pola[randY][randX] != NULL) {
		this->randX = rand() % szerokosc;
		this->randY = rand() % wysokosc;
	}
}


int Swiat::GetTura()
{
	return this->tura;
}

Organizm* Swiat::GetPole(int x, int y)
{
	return Pola[y][x];
}

void Swiat::SetPole(Organizm* org,int x,int y)
{
	Pola[y][x] = org;
}


bool Swiat::ZapiszSwiat(const std::string& sciezkaDoZapisu)
{
	std::ofstream file;
	file.open(sciezkaDoZapisu);
	if (!file.good())
	{
		cout << "nie udalo sie";
		return false;
	}
	file << wysokosc << ' ' << szerokosc << endl;
	for (auto organizm : Organizmy)
		file << organizm->ZapiszOrganizm() << endl;
	file << (int)'K';
	file.close();
}

bool Swiat::ZaladujSwiat(const std::string& sciezkaDoPlikuZapisu)
{
	std::ifstream file(sciezkaDoPlikuZapisu);
	if (!file.good())
		return false;

	Organizm* organizm = nullptr;

	int wysokosc,szerokosc;
	file >> wysokosc >> szerokosc;
	
	this->nowaGra(wysokosc, szerokosc);

	int gatunek;
	
	int x, y, sila, inicjatywa, umiejetnosc, cooldown;
	while (true)
	{
		file >> gatunek>>x>>y>>sila>>inicjatywa;
		if (gatunek == 'K')
		{
			break;
		}

		switch ((char)gatunek)
		{
		case 'C':
			file >> umiejetnosc >> cooldown;
			organizm=new Czlowiek(this,x,y,umiejetnosc,cooldown);
			break;
		case 'A':
			organizm= new Antylopa(this,x,y);
			break;
		case 'L':
			organizm= new Lis(this, x, y);
			break;
		case 'O':
			organizm= new Owca(this, x, y);
			break;
		case 'W':
			organizm= new Wilk(this, x, y);
			break;
		case 'Z':
			organizm= new Zolw(this, x, y);
			break;
		case 'B':
			organizm= new BarszczSosnowskiego(this, x, y);
			break;
		case 'G':
			organizm= new Guarana(this, x, y);
			break;
		case 'M':
			organizm= new Mlecz(this, x, y);
			break;
		case 'T':
			organizm= new Trawa(this, x, y);
			break;
		case 'J':
			organizm= new WilczeJagody(this, x, y);
			break;
		}

		organizm->SetSila(sila);
		organizm->SetInicjatywa(inicjatywa);
		this->Organizmy.push_back(organizm);

	}

	
	return true;
}

void Swiat::nowaGra(int wysokosc,int szerokosc)
{
		system("cls");

		for (int i = 0; i < this->wysokosc; i++)
		{
			for (int j = 0; j < this->szerokosc; j++)
			{
				this->Pola[i][j] = NULL;
			}
		}
		
		for (int i = Organizmy.size() - 1; i >= 0; i--) {
				delete Organizmy[i];
				Organizmy.erase(Organizmy.begin() + i);
		}

		this->wysokosc = wysokosc;
		this->szerokosc = szerokosc;
}