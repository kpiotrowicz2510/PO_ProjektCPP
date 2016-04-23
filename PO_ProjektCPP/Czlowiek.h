#pragma once
#include "Zwierze.h"
	namespace Zwierzeta {
		class Czlowiek : public Zwierze
		{
		public:
			Czlowiek(Swiat &swiat);
			~Czlowiek();
			void akcja(); //Poruszanie strzalkami
			void kolizja(); //Super umiejetnosc przez 5 tur
			bool IsSpecial();
		private:
			int key = 0;
			int tura_aktywacji = 0;
			int cooldown = 0;
			bool special = false;
		};
	}