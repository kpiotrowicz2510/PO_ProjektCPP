#include "Antylopa.h"



Antylopa::Antylopa(Swiat &swiat)
{
	this->SetSwiat(swiat);
	this->inicjatywa = 4;
	this->sila = 4;
}


Antylopa::~Antylopa()
{
}

void Antylopa::akcja() {
	srand(time(NULL));
	int x = rand() % 3;
	if (x == 1) {
		this->SetX(this->GetX() - 2);
	}
	if (x == 2) {
		this->SetX(this->GetX() + 2);
	}
	int y = rand() % 3;
	if (y == 1) {
		this->SetY(this->GetY() - 2);
	}
	if (y == 2) {
		this->SetY(this->GetY() + 2);
	}
}

void Antylopa::kolizja() {
	Organizm *org = this->GetSwiat()->podajOrganizm(this->GetX(), this->GetY());
	if (this->GetSwiat()->freeSpace(this->GetX(), this->GetY()) == false) {
		if (this->GetID() != org->GetID()) {
			if (org->GetSymbol() == this->GetSymbol()) {
				this->rozmnazanie();
			}
			else {
				int g = rand() % 2;
				if (g == 1) {
					this->walka(org);
				}
				else {
					try {
						point a = this->GetSwiat()->freeSpaceP(this->GetX(), this->GetY());
					
					this->SetX(a.x);
					this->SetY(a.y);
					}
					catch (exception e) {
						this->GetSwiat()->addInfo("Brak pustego miejsca!");
					}
				}
			}
		}
	}
}