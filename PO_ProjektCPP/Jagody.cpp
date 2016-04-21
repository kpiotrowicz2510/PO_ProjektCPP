#include "Jagody.h"



Jagody::Jagody(Swiat &swiat)
{
	this->SetSwiat(swiat);
	this->sila = 99;
	this->inicjatywa = 0;
}


Jagody::~Jagody()
{
}
void Jagody::akcja() {

}
void Jagody::kolizja() {
	Organizm *org = this->GetSwiat()->podajOrganizm(this->GetX(), this->GetY());
	if ((*org).GetID() != this->GetID()) {
		this->GetSwiat()->deleteOrganizm(this->GetID());
		this->GetSwiat()->deleteOrganizm((*org).GetID());
		string a;
		a = "Organizm (";
		a += this->GetSymbol();
		a += ") zabija (";
		a += (*org).GetSymbol();
		a += ")";
		this->GetSwiat()->addInfo(a);
	}
}