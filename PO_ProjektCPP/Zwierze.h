#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	virtual void akcja();//Przesuwanie w losowe sasiednie pole
	virtual void kolizja(); //Ten sam gatunek - rozmnazanie
	void rozmnazanie();
	void walka(Organizm* a1);
	void uciekaj();
	Zwierze* operator = (const Zwierze &right) {
		this->inicjatywa = (right).inicjatywa;
		this->sila = (right).sila;
		this->swiat = (right).swiat;
	}
};

