#include "Mlecz.h"



Mlecz::Mlecz(Swiat &swiat)
{
	this->SetSwiat(swiat);
	this->sila = 0;
	this->inicjatywa = 0;
}


Mlecz::~Mlecz()
{
}

void Mlecz::akcja() {
	for (int i = 0; i < 3;i++){
		int v = rand() % 100;
		if (v == 20) {
			try {
			point a = this->GetSwiat()->freeSpaceP(this->GetX(), this->GetY());			

			const Roslina& g = *this;
			Roslina *z = new Roslina(g);

			(*z).SetX(a.x);
			(*z).SetY(a.y);
			if (a.x > -1 && a.y > -1) {
				this->GetSwiat()->addOrganizm(z, a.x, a.y);
			}
			}
			catch (exception e) {
				this->GetSwiat()->addInfo("Brak pustego miejsca!");
			}
		}
	}
}