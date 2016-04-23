#include "Owca.h"


namespace Zwierzeta {
	Owca::Owca(Swiat &swiat)
	{
		this->SetSwiat(swiat);
		this->inicjatywa = 4;
		this->sila = 4;
	}


	Owca::~Owca()
	{
	}
}
