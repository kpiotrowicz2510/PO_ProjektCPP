#include "Zolw.h"


namespace Zwierzeta {
	Zolw::Zolw(Swiat &swiat)
	{
		this->SetSwiat(swiat);
		this->inicjatywa = 1;
		this->sila = 2;
	}


	Zolw::~Zolw()
	{
	}

	void Zolw::akcja() {
		int x = rand() % 8;
		if (x == 7) {
			this->SetX(this->GetX() - 1);
		}
		if (x == 8) {
			this->SetX(this->GetX() + 1);
		}
		int y = rand() % 8;
		if (y == 7) {
			this->SetY(this->GetY() - 1);
		}
		if (y == 8) {
			this->SetY(this->GetY() + 1);
		}
	}

	void Zolw::kolizja() {
		Organizm *org = this->GetSwiat()->podajOrganizm(this->GetX(), this->GetY());
		if (this->GetSwiat()->freeSpace(this->GetX(), this->GetY()) == false) {
			if (this->GetID() != org->GetID()) {
				if (org->GetSymbol() == this->GetSymbol()) {
					this->rozmnazanie();
				}
				else {
					if ((*org).GetSila() < 5) {
						(*org).SetX((*org).GetLastX());
						(*org).SetY((*org).GetLastY());
					}
					else {
						this->walka(org);
					}
				}
			}
		}
	}
}