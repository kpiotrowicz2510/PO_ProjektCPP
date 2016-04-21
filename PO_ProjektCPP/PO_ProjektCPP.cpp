#include "stdafx.h"
#include "Inkludy.h"

int main()
{
	//GITSAVE
	Swiat *swiat = new Swiat();
	(*swiat).spawnObjects();
	(*swiat).updateLoop();
    return 0;
}

