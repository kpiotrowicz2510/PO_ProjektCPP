#include "stdafx.h"
#include "Inkludy.h"

int main()
{
	Swiat *swiat = new Swiat();	
	(*swiat).spawnObjects();
	(*swiat).updateLoop();
    return 0;
}

