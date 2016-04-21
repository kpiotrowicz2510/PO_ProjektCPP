#pragma once
#include "Roslina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(Swiat &swiat);
	~Guarana();
	void kolizja(); //dodaje 3 do sily
};

