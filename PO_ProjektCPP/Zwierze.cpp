#include "Zwierze.h"
namespace Zwierzeta {
	void Zwierze::akcja() {
		int x = rand() % 3;
		if (x == 1) {
			this->SetX(this->GetX() - 1);
		}
		if (x == 2) {
			this->SetX(this->GetX() + 1);
		}
		int y = rand() % 3;
		if (y == 1) {
			this->SetY(this->GetY() - 1);
		}
		if (y == 2) {
			this->SetY(this->GetY() + 1);
		}
	}

	void Zwierze::kolizja() {
		Organizm *org = this->GetSwiat()->podajOrganizm(this->GetX(), this->GetY());
		
		if (this->GetSwiat()->freeSpace(this->GetX(), this->GetY()) == false) {
			if (this->GetID() != org->GetID()) {
				if (org->GetSymbol() == this->GetSymbol()) {
					this->rozmnazanie();
				}
				else {
					this->walka(org);
				}
			}
		}
	}
	void Zwierze::rozmnazanie() {
		try {
			point a = this->GetSwiat()->freeSpaceP(this->GetX(), this->GetY());

			const Zwierze& g = *this;
			Zwierze *z = new Zwierze(g);

			(*z).SetX(a.x);
			(*z).SetY(a.y);
			if (a.x > -1 && a.y > -1) {
				this->GetSwiat()->addOrganizm(z, a.x, a.y);
			}
		}
		catch (exception e) {
			this->GetSwiat()->addInfo("Wyjatek: Brak pustego miejsca!");
		}
	}

	void Zwierze::walka(Organizm* a1) {
		if (this->GetSila() > (*a1).GetSila()) {
			this->GetSwiat()->deleteOrganizm((*a1).GetID());
			string a;
			a = "Organizm (";
			a += this->GetSymbol();
			a += ") zabija (";
			a += (*a1).GetSymbol();
			a += ")";
			this->GetSwiat()->addInfo(a);
		}
		if (this->GetSila() < (*a1).GetSila()) {
			this->GetSwiat()->deleteOrganizm(this->GetID());
			string a;
			a = "Organizm (";
			a += (*a1).GetSymbol();
			a += ") zabija (";
			a += this->GetSymbol();
			a += ")";
			this->GetSwiat()->addInfo(a);
		}
		if (this->GetSila() == (*a1).GetSila()) {
			this->GetSwiat()->deleteOrganizm((*a1).GetID());
			string a;
			a = "Organizm (";
			a += this->GetSymbol();
			a += ") zabija (";
			a += (*a1).GetSymbol();
			a += ")";
			this->GetSwiat()->addInfo(a);
		}
	}
	void Zwierze::uciekaj() {
		this->SetX(this->GetLastX());
		this->SetY(this->GetLastY());
	}
}