#include "Guarana.h"



Guarana::Guarana(Swiat &swiat)
{
	this->SetSwiat(swiat);
	this->sila = 0;
	this->inicjatywa = 0;
}


Guarana::~Guarana()
{
}

void Guarana::kolizja() {
	Organizm *org = this->GetSwiat()->podajOrganizm(this->GetX(), this->GetY());
	if ((*org).GetID() != this->GetID() && (*org).GetSymbol() != this->GetSymbol()) {
		(*org).SetSila((*org).GetSila() + 3);
		this->GetSwiat()->deleteOrganizm(this->GetID());
	}
}