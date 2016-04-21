#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{
public:
	Antylopa(Swiat &swiat);
	~Antylopa();
	void akcja(); //Zasieg ruchu 2
	void kolizja();
};

