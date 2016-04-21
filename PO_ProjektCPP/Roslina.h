#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	virtual void akcja(); //Przesuwanie w losowe sasiednie pole
	virtual void kolizja();
	Roslina* operator = (const Roslina &right) {
		this->inicjatywa = (right).inicjatywa;
		this->sila = (right).sila;
		this->swiat = (right).swiat;
		//this->symbol = (right).symbol;
	}
};

