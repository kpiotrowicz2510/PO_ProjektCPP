#pragma once
#include "conio2.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <iterator>
#include "Organizm.h"

#define filename "swiat.txt"
using namespace std;

class Organizm;
struct point {
	int x;
	int y;
};
class Swiat
{
public:
	vector <Organizm*> organizmy;
	int tura_numer;
	int pressed_key = 0;
	Swiat();
	~Swiat();
	void wykonajTure(int key);
	void rysujSwiat();
	bool freeSpace(int x, int y);
	point freeSpaceP(int x, int y);
	void addOrganizm(Organizm *o);
	void addOrganizm(Organizm *o,int x,int y);
	void deleteOrganizm(int id);
	void SetCzlowiek(Organizm * c);
	void zapiszSwiat();
	void wczytajSwiat();
	Organizm * GetCzlowiek();
	void Napis(int x, int y, string str);
	Organizm* Swiat::podajOrganizm(int x, int y);
	void addInfo(string s);
	void spawnObjects();
	void updateLoop();
	int GetRX();
	int GetRY();
private:
	Organizm * czlowiek;
	int new_id;
	char *org_c;
	int sRX;
	int sRY;
protected:
	vector <string> info;
};