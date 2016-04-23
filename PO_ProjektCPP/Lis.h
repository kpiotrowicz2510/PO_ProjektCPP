#pragma once
#include "Zwierze.h"
namespace Zwierzeta {
	class Lis :
		public Zwierze
	{
	public:
		Lis(Swiat &swiat);
		~Lis();
		void akcja(); //Nie ruszy sie na pole zajmowane
	};
}