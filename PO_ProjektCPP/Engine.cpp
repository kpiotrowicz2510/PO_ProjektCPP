#include "Engine.h"



Engine::Engine(Swiat &swiat)
{
	textmode(C80);
	this->organizmy = new char*[20];
	for (int i = 0; i < 20; i++) {
		this->organizmy[i] = new char[20];
	}
}

void Engine::AddOrganizm(Organizm* o) {
	if (o == nullptr) { return; }
	this->organizmy[o->GetY()][o->GetX()] = o->symbol;
}

void Engine::Update() {
	char a = '0';
	do {
		this->DrawGame();

		a = getch();
		Klawiatura(a);
	} while (a != 'q');
}

void Engine::DrawGame() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			gotoxy( j + 1, i + 1);
			switch (this->organizmy[i][j]) {
			case 36:
				textcolor(YELLOW);
				break;
			case 48:
				textcolor(MAGENTA);
				break;
			default:
				textcolor(WHITE);
				break;
			}
			putch((int)this->organizmy[i][j]);
		}
	}
	/*
	//Narysuj gracza
	textcolor(CYAN);
	gotoxy(x + (*pos).X + 1, y + (*pos).Y + 1);
	putch(game.playerImg);

	//Narysuj czas i ruchy
	textcolor(YELLOW);
	Napis(55, 0, "Czas: ");
	cout << game.czas << "s  Ruchy:" << game.ruchy;
	*/
}

void Engine::Klawiatura(char a) {

}

Engine::~Engine()
{
}
