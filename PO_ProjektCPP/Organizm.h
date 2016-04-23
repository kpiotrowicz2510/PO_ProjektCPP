#pragma once
#include <string>
#include <iostream>
#include "Swiat.h"

class Swiat;
class Organizm
{
public:
	const int GetX();
	const int GetY();
	Swiat* GetSwiat();
	const char GetSymbol();
	void SetSymbol(char symbol);
	void SetID(int id);
	const int GetID();
	void SetX(int value);
	void SetY(int value);
	void SetSwiat(Swiat &swiat);
	void SetSila(int value);
	int GetSila() const;
	int GetInicjatywa() const;
	const int GetLastX();
	const int GetLastY();
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	void rysowanie() {
		gotoxy(this->GetX() + 2, this->GetY() + 2);
		putch((int)this->symbol);
	}
	bool operator < (const Organizm& org) {
		return (inicjatywa < org.GetInicjatywa());
	}
protected:
	int sila;
	int inicjatywa;
	Swiat *swiat;
private:
	int id;
	char symbol;
	int posX;
	int posY;
	int last_posX;
	int last_posY;
};