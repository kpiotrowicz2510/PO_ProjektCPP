#pragma once
#include "Roslina.h"
class Jagody :
	public Roslina
{
public:
	Jagody(Swiat &swiat);
	~Jagody();
	void akcja();
	void kolizja();
};

