#include "griglia.h"
#include <iostream>
#include "colori.h"

Griglia::Griglia() {	// creiamo il constructor

	numRighe = 20;		// gli assegnamo i valori di righe e colonne
	numColonne = 10;
	grandCella = 50 * prop;

	Inizializza();
	colori = OttieniColoreCella();
}

void Griglia::Inizializza() {	// diamo a tutte le celle il valore 0

	for (int riga = 0; riga < numRighe; riga++) {
		for (int colonna = 0; colonna < numColonne; colonna++) {
			griglia[riga][colonna] = 0;
		}
	}
}

void Griglia::Print() {
	for (int riga = 0; riga < numRighe; riga++) {
		for (int colonna = 0; colonna < numColonne; colonna++) {
			std::cout << griglia[riga][colonna] << " ";
		}
		std::cout << "\n";
	}
}

void Griglia::Disegna() {
	
	for (int riga = 0; riga < numRighe; riga++) {
		for (int colonna = 0; colonna < numColonne; colonna++) {
			
			int valoreCella = griglia[riga][colonna];	// assegnamo al valore cella un valore per una determinata cella che conterrà l'indice del colore del vettore
			DrawRectangle((colonna * grandCella + 21) * prop, (riga * grandCella + 21) * prop, (grandCella - 1) * prop, (grandCella - 1) * prop, colori[valoreCella]);
			// creiamo ad ogni index una cella, che avrà offset di 1 e grandezza di 49, così creeremo la prossima cella a 51 sullo schermo, con grandezza 49        21
		}
	}
}

bool Griglia::laCellaFuori(int riga, int colonna) {
	
	if (riga >= 0 && riga < numRighe && colonna >= 0 && colonna < numColonne) {
		return false;
	}
	
	return true;
}

bool Griglia::laCellaVuota(int riga, int colonna){
	
	if (griglia[riga][colonna] == 0) {
		return true;
	}
	return false;
}

int Griglia::pulisciTutteRighe() {

	int completate = 0;
	for (int riga = numRighe - 1; riga >= 0; riga--)
	{
		if (laRigaPiena(riga))
		{
			pulisciRiga(riga);
			completate++;
		}
		else if (completate > 0)
		{
			muoviRigaSotto(riga, completate);
		}
	}
	return completate;
}

bool Griglia::laRigaPiena(int riga) {

	for (int colonna = 0; colonna < numColonne; colonna++)
	{
		if (griglia[riga][colonna] == 0)
		{
			return false;
		}
	}
	return true;
}

void Griglia::pulisciRiga(int riga) {

	for (int colonna = 0; colonna < numColonne; colonna++)
	{
		griglia[riga][colonna] = 0;
	}
}

void Griglia::muoviRigaSotto(int riga, int numRighe) {

	for (int colonna = 0; colonna < numColonne; colonna++)
	{
		griglia[riga + numRighe][colonna] = griglia[riga][colonna];
		griglia[riga][colonna] = 0;
	}
}