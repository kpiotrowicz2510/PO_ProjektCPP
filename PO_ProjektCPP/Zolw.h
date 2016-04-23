#pragma once
#include "Zwierze.h"
namespace Zwierzeta {
	class Zolw :
		public Zwierze
	{
	public:
		Zolw(Swiat &swiat);
		~Zolw();
		void akcja(); //75% nie zmienia polozenia
		void kolizja(); //Odpiera o sile <5
	};
}