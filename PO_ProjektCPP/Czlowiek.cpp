#include "Czlowiek.h"



Czlowiek::Czlowiek(Swiat &swiat)
{
	this->SetSwiat(swiat);
	this->sila = 5;
	this->inicjatywa = 4;
}


Czlowiek::~Czlowiek()
{
}

void Czlowiek::akcja() {
	int key = this->GetSwiat()->pressed_key;
	if (key == 4&&this->special==false&&cooldown==0) {
		this->GetSwiat()->addInfo("Tarcza Alzura aktywowana!");
		this->special = true;
		this->tura_aktywacji = this->GetSwiat()->tura_numer;
	}
	if (this->GetSwiat()->tura_numer - this->tura_aktywacji > 5&&this->special==true) {
		this->special = false;
		this->cooldown = 5;
		this->GetSwiat()->addInfo("Tarcza Alzura dezaktywowana!");
	}
	if (this->cooldown > 0) {
		this->cooldown--;
	}
	this->GetSwiat()->pressed_key = -1;
	int x = this->GetX();
	int y = this->GetY();
	int gx = this->GetX();
	int gy = this->GetY();
	if (x- 1 >= 0) {
		if (key == 2) {
			this->SetX(gx - 1);
			return;
		}
	}
	if(x + 1 <= RX){
		if (key == 3) {
			this->SetX(gx + 1);
			return;
		}
	}
	if (y - 1 >= 0) {
		if (key == 0) {
			this->SetY(gy - 1);
			return;
		}
	}
	if(y + 1 <= RY){
		if (key == 1) {
			this->SetY(gy + 1);
			return;
		}
	}
}
void Czlowiek::kolizja() {
	cout << "ERROR";
}
bool Czlowiek::IsSpecial() {
	return this->special;
}