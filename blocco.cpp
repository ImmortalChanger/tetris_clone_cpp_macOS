#include "blocco.h"

Blocco::Blocco() {

	grandezzaCella = 50;
	statoRotazione = 0;
	colori = OttieniColoreCella();
	offsetRiga = 0;
	offsetColonna = 0;

}

void Blocco::Disegna(int offsetx, int offsety) {

	std::vector<Posizione> soglie = Blocco::OttieniPosizioneCelle();
	for (Posizione oggetto : soglie) {
		DrawRectangle(oggetto.colonna * grandezzaCella + offsetx, oggetto.riga * grandezzaCella + offsety, grandezzaCella - 1, grandezzaCella - 1, colori[id]);
	} // usiamo gli offset per disegnare (in modo diverso) i blocchi successivi
}

void Blocco::Movimento(int rows, int columns) {

    offsetRiga += rows;
    offsetColonna += columns;
}

std::vector<Posizione> Blocco::OttieniPosizioneCelle() {

    std::vector<Posizione> soglie = celle[statoRotazione];
    std::vector<Posizione> soglieMosse;
    for (Posizione oggetto : soglie)
    {
        Posizione nuovaPos = Posizione(oggetto.riga + offsetRiga, oggetto.colonna + offsetColonna);
        soglieMosse.push_back(nuovaPos);
    }
    return soglieMosse;
}

void Blocco::Ruota() {

    statoRotazione++;
    if (statoRotazione == (int)celle.size()) {  // celle.size() restituisce la grandezza della cella, che arriva fino a 4
        statoRotazione = 0;
    }
}

void Blocco::RuotaIndietro() {

    statoRotazione--;
    if (statoRotazione == -1) {     // se la cella arriva allo stato rotazione -1 la si riporta al quarto - 1
        statoRotazione = celle.size() - 1;
    }
}

