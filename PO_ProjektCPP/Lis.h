#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(Swiat &swiat);
	~Lis();
	void akcja(); //Nie ruszy sie na pole zajmowane
};

