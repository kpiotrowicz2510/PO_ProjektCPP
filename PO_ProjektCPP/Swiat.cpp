#include "Inkludy.h"

using namespace Zwierzeta;
using namespace Rosliny;

Swiat::Swiat()
{
	srand(time(NULL));
	this->new_id = 0;
	textmode(C80);
	cout << "Podaj rozmiar swiata \nX:\n";
	int x, y;
	char *h = new char[3];
	int a=0;
	int i = 0;
	do {
		a = getch();
		putch(a);
		h[i] = (char)a;
		i++;
	}
	while (h[i-1]!='\r');
	x = atoi(h);
	putch('\n');
	h = new char[3];
	i = 0;
	a = 0;
	cout << "Y:\n";
	do {
		a = getch();
		putch(a);
		h[i] = (char)a;
		i++;
	} while (h[i - 1] != '\r');
	y = atoi(h);
	this->sRX = x;
	this->sRY = y;
	this->org_c = new char[this->sRX*this->sRY];
	for (int i = 0; i < this->sRX*this->sRY; i++)
	{
		this->org_c[i] = ' ';
	}
	this->tura_numer = 0;
}


Swiat::~Swiat()
{
}

void Swiat::spawnObjects() {
	Czlowiek *cz = new Czlowiek(*this);
	(*cz).SetSymbol('C');
	this->SetCzlowiek(cz);
	this->addOrganizm(cz);
	Wilk *w = new Wilk(*this);
	(*w).SetSymbol('W');
	Wilk *w3 = new Wilk(*this);
	(*w3).SetSymbol('W');
	Zolw *z = new Zolw(*this);
	(*z).SetSymbol('Z');
	Zolw *z2 = new Zolw(*this);
	(*z2).SetSymbol('Z');
	Antylopa *am = new Antylopa(*this);
	(*am).SetSymbol('A');
	Antylopa *am1 = new Antylopa(*this);
	(*am1).SetSymbol('A');
	Owca *o = new Owca(*this);
	(*o).SetSymbol('O');
	Owca *o2 = new Owca(*this);
	(*o2).SetSymbol('O');
	Wilk *w2 = new Wilk(*this);
	(*w2).SetSymbol('W');
	Mlecz *m = new Mlecz(*this);
	(*m).SetSymbol('m');
	Trawa *t = new Trawa(*this);
	(*t).SetSymbol('T');
	Jagody *j1 = new Jagody(*this);
	(*j1).SetSymbol('J');
	Jagody *j2 = new Jagody(*this);
	(*j2).SetSymbol('J');
	Guarana *g1 = new Guarana(*this);
	(*g1).SetSymbol('G');
	Guarana *g2 = new Guarana(*this);
	(*g2).SetSymbol('G');
	Lis *l1 = new Lis(*this);
	(*l1).SetSymbol('L');
	Lis *l2 = new Lis(*this);
	(*l2).SetSymbol('L');
	this->addOrganizm(w);
	this->addOrganizm(w2);
	this->addOrganizm(z);
	this->addOrganizm(z2);
	this->addOrganizm(w3);
	this->addOrganizm(am);
	this->addOrganizm(am1);
	this->addOrganizm(m);
	this->addOrganizm(t);
	this->addOrganizm(j1);
	this->addOrganizm(j2);
	this->addOrganizm(o);
	this->addOrganizm(o2);
	this->addOrganizm(g1);
	this->addOrganizm(g2);
	this->addOrganizm(l1);
	this->addOrganizm(l2);
}
void Swiat::updateLoop() {
	int a = 0;
	do {
		if (a == '1') {
			this->zapiszSwiat();
		}
		else {
			if (a == '2') {
				this->wczytajSwiat();
			}
			else {
				this->wykonajTure(a);
			}
		}
		this->rysujSwiat();
		a = getch();
		if (a == 0) {
			a = getch();
		}
	} while (a != 'q');
}
void Swiat::wykonajTure(int key)
{
	switch (key) {
	case 72: //str up			
		this->pressed_key = 0;
		break;
	case 80: //str down			
		this->pressed_key = 1;
		break;
	case 77: //str prawo						
		this->pressed_key = 3;
		break;
	case 75: //str lewo	
		this->pressed_key = 2;
		break;
	case 32: //str lewo	
		this->pressed_key = 4;
		break;
	}
	for (int i = 0; i < this->sRX*this->sRY; i++)
	{
		this->org_c[i] = ' ';
	}
	for (int i = 0; i < this->organizmy.size(); i++) {
		this->organizmy[i]->akcja();
		if (this->org_c[this->organizmy[i]->GetY() * this->sRX + this->organizmy[i]->GetX()] != ' ') {
			this->organizmy[i]->kolizja();
		}
		else {
			this->org_c[this->organizmy[i]->GetY() * this->sRX + this->organizmy[i]->GetX()] = this->organizmy[i]->GetSymbol();
		}
	}
	this->tura_numer++;
}

void Swiat::rysujSwiat()
{
	clrscr();
	int hx = 0;
	int hy = 0;
	for (int i = 0; i < (this->sRX + 1)*(this->sRY + 2); i++)
	{
		if (hx == 0 || hy == 0 || hx == this->sRX || hy == this->sRY + 1) {
			gotoxy(hx + 1, hy + 1);
			putch('#');
		}

		hx++;
		if (hx > this->sRX) {
			hy++;
			hx = 0;
		}
	}
	for (int i = 0; i < this->organizmy.size(); i++) {
		this->organizmy[i]->rysowanie();
	}
	char* x = new char[5];
	itoa(this->czlowiek->GetSila(), x, 10);


	string f = "Sila czlowieka: ";
	f += x;

	this->Napis(this->sRX + 10, 0, "Krzysztof Piotrowicz 160873");
	this->Napis(this->sRX + 10, 2, f);
	this->Napis(this->sRX + 10, 4, "Ostatnie wydarzenia w swiecie:");
	int o = 6;

	for (int i = this->info.size() - 1; i > this->info.size() - 15; i--) {
		this->Napis(this->sRX + 10, o, this->info[i]);
		o++;
	}
}
bool Swiat::freeSpace(int x, int y) {
	if (this->org_c[y * this->sRX + x] != ' ') {
		return false;
	}
	return true;
}

point Swiat::freeSpaceP(int x2, int y2) {
	int xs = 0;
	int ys = 0;
	if (x2 == 0) {
		xs = 1;
	}
	if (y2 == 0) {
		ys = 1;
	}
	for (int y = -1 + ys; y < 2 + ys; y++) {
		for (int x = -1 + xs; x < 2 + xs; x++) {
			if (this->org_c[(y2 + y)*this->sRX + (x2 + x)] == ' ') {
				point *xz = new point();
				(*xz).x = x2 + x;
				(*xz).y = y2 + y;
				return *xz;
			}
		}
	}
	throw exception();
}

Organizm* Swiat::podajOrganizm(int x, int y) {
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i]->GetX() == x &&this->organizmy[i]->GetY() == y) {
			return this->organizmy[i];
		}
	}
	return nullptr;
}

void Swiat::addOrganizm(Organizm * o) {
	int x = rand() % this->sRX;
	int y = rand() % this->sRY;
	o->SetX(x);
	o->SetY(y);
	if (this->freeSpace(x, y) == false) {
		return;
	}
	this->org_c[(y)*this->sRX + (x)] = o->GetSymbol();
	o->SetID(this->new_id);
	this->new_id++;
	this->organizmy.push_back(o);
	sort(this->organizmy.begin(), this->organizmy.end());
	string s = "Utworzono nowy organizm - ";
	s += o->GetSymbol();
	this->info.push_back(s);
}
void Swiat::addOrganizm(Organizm * o, int x, int y) {
	o->SetX(x);
	o->SetY(y);

	if (this->freeSpace(x, y) == false) {
		string s = "Nie mozna utworzyc nowego organizmu!- ";
		s += o->GetSymbol();
		this->info.push_back(s);
	}
	this->org_c[(y)*this->sRX + (x)] = o->GetSymbol();
	o->SetID(this->new_id);
	this->new_id++;
	this->organizmy.push_back(o);
	sort(this->organizmy.begin(), this->organizmy.end());
	string s = "Utworzono nowy organizm - ";
	s += o->GetSymbol();
	this->info.push_back(s);
}

void Swiat::Napis(int x, int y, string str) {
	for (int i = 0; i < str.length(); i++) {
		gotoxy(x + 1 + i, y + 1);
		putch(str.c_str()[i]);
	}
}

void Swiat::deleteOrganizm(int id) {
	int del_id = -1;
	for (int i = 0; i < this->organizmy.size(); i++) {
		if (this->organizmy[i]->GetID() == id) {
			del_id = i;
		}
	}
	if (del_id > -1) {
		Organizm * a;
		this->organizmy.erase(this->organizmy.begin() + del_id);
		char y[5];
		itoa(del_id, y, 10);
		string s = "usunieto organizm o _id = ";
		s += y;
	}
}
void Swiat::addInfo(string s) {
	this->info.push_back(s);
}
void Swiat::SetCzlowiek(Organizm* c) {
	this->czlowiek = c;
}
Organizm* Swiat::GetCzlowiek() {
	return this->czlowiek;
}
void Swiat::zapiszSwiat() {
	ofstream outfile;
	outfile.open(filename);
	string dane = "";
	dane.append(to_string(this->GetRX()));
	dane.append("\t");
	dane.append(to_string(this->GetRY()));

	outfile << dane << endl;

	outfile << to_string(this->new_id) << "\t" << to_string(this->tura_numer) << endl;

	outfile << to_string(this->organizmy.size()) << endl;


	for (int i = 0; i < this->organizmy.size(); i++) {
		dane = "";
		dane += to_string(this->organizmy[i]->GetID()) + "\n" + this->organizmy[i]->GetSymbol() + "\n" + to_string(this->organizmy[i]->GetInicjatywa()) + "\n" + to_string(this->organizmy[i]->GetSila()) + "\n" + to_string(this->organizmy[i]->GetX()) + "\n" + to_string(this->organizmy[i]->GetY()) + "\n";
		outfile << dane;
	}
	outfile.close();
	string s = "Zapisano stan do pliku!";
	this->info.push_back(s);
}
void Swiat::wczytajSwiat() {
	this->organizmy.clear();
	ifstream infile;
	infile.open(filename);
	char data[1000];
	int linia = 0;


	int nid, tura, ilosc;
	int rx, ry;
	infile >> rx >> ry;
	
	this->sRX = rx;
	this->sRY = ry;

	infile >> nid >> tura >> ilosc;

	this->org_c = new char[this->sRX*this->sRY];
	for (int i = 0; i < this->sRX*this->sRY; i++)
	{
		this->org_c[i] = ' ';
	}

	while (linia < ilosc) {
		int id, inic, sila, x, y;
		char symbol;
		infile >> id >> symbol >> inic >> sila >> x >> y;

		if (symbol == 'W') {
			Wilk *o = new Wilk(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'Z') {
			Zolw *o = new Zolw(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'L') {
			Lis *o = new Lis(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'G') {
			Guarana *o = new Guarana(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'J') {
			Jagody *o = new Jagody(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'O') {
			Owca *o = new Owca(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'A') {
			Antylopa *o = new Antylopa(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'C') {
			Czlowiek *o = new Czlowiek(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'm') {
			Mlecz *o = new Mlecz(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}
		if (symbol == 'T') {
			Trawa *o = new Trawa(*this);
			(*o).SetID(id);
			(*o).SetSila(sila);
			(*o).SetSymbol(symbol);
			(*o).SetX(x);
			(*o).SetY(y);
			this->addOrganizm(o,x,y);
		}

		linia++;
	}
	infile.close();
	string s = "Wczytano stan z pliku!";
	this->info.push_back(s);
}

const int Swiat::GetRX() {
	return this->sRX;
}

const int Swiat::GetRY() {
	return this->sRY;
}

const int Swiat::GetTura() {
	return this->tura_numer;
}

const int Swiat::GetPressedKey() {
	return this->pressed_key;
}