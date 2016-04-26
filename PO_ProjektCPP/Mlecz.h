#pragma once
#include "Roslina.h"
namespace Rosliny {
	class Mlecz :
		public Roslina
	{
	public:
		Mlecz(Swiat &swiat);
		~Mlecz();
		void akcja(); //3 proby rozprzestrzeniania w 1  turze
	};
}