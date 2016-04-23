#include "Organizm.h"

Swiat* Organizm::GetSwiat() {
	return this->swiat;
}
void Organizm::SetSwiat(Swiat &swiat) {
	this->swiat = &swiat;
	this->SetX(0);
	this->SetY(0);
	this->SetSila(0);
}
const int Organizm::GetLastX() { return this->last_posX; }
const int Organizm::GetLastY() { return this->last_posY; }
const int Organizm::GetX() { return this->posX; }
const int Organizm::GetY() { return this->posY; }
void Organizm::SetX(int value) {
	if (value > -1 && value < this->GetSwiat()->GetRX() - 1) {
		this->last_posX = this->posX;
		this->posX = value;
	}
}
void Organizm::SetY(int value) {
	if (value > -1 && value < this->GetSwiat()->GetRY()) {
		this->last_posY = this->posY;
		this->posY = value;
	}
}
int Organizm::GetInicjatywa() const {
	return this->inicjatywa;
}
int Organizm::GetSila() const {
	return this->sila;
}
void Organizm::SetID(int id) {
	this->id = id;
}
const int Organizm::GetID() {
	return this->id;
}
const char Organizm::GetSymbol() {
	return this->symbol;
}
void Organizm::SetSymbol(const char symbol) {
	this->symbol = symbol;
}
void Organizm::SetSila(int value) {
	if (value > 0) {
		this->sila = value;
	}
}