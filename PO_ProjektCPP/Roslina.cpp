#include "Roslina.h"
namespace Rosliny {
	void Roslina::kolizja() {
		Organizm *org = this->GetSwiat()->podajOrganizm(this->GetX(), this->GetY());
		if ((*org).GetID() != this->GetID() && (*org).GetSymbol() != this->GetSymbol()) {
			this->GetSwiat()->deleteOrganizm(this->GetID());
			string a;
			a = "Organizm (";
			a += (*org).GetSymbol();
			a += ") zjada (";
			a += this->GetSymbol();
			a += ")";
			this->GetSwiat()->addInfo(a);
		}
	}
	void Roslina::akcja() {
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