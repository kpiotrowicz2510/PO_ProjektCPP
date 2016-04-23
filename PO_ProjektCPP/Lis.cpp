#include "Lis.h"
	namespace Zwierzeta {
		Lis::Lis(Swiat &swiat)
		{
			this->SetSwiat(swiat);
			this->inicjatywa = 7;
			this->sila = 3;
		}


		Lis::~Lis()
		{
		}

		void Lis::akcja() {
			int mx = 0;
			int my = 0;
			int x = rand() % 2;
			if (x == 0) {
				mx = this->GetX() - 1;
			}
			if (x == 1) {
				mx = this->GetX() + 1;
			}
			int y = rand() % 2;
			if (y == 0) {
				my = this->GetY() - 1;
			}
			if (y == 1) {
				my = this->GetY() + 1;
			}
			Organizm *org = this->GetSwiat()->podajOrganizm(mx, my);
			if (org == nullptr) {
				this->SetX(mx);
				this->SetY(my);
			}
			else {
				if ((*org).GetSila() > this->GetSila()) {}
				else {
					this->SetX(mx);
					this->SetY(my);
				}
			}
		}
	}