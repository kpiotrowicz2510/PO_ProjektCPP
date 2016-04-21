#pragma once
#include "Roslina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(Swiat &swiat);
	~Mlecz();
	void akcja(); //3 proby rozprzestrzeniania w 1  turze
	void kolizja(){}
};

