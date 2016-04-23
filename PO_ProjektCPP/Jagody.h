#pragma once
#include "Roslina.h"
	namespace Rosliny {
		class Jagody :
			public Roslina
		{
		public:
			Jagody(Swiat &swiat);
			~Jagody();
			void akcja();
			void kolizja();
		};

	}