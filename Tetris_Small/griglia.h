#pragma once
#include <vector>
#include <raylib.h>

class Griglia {

	public:
		Griglia();
		void Inizializza();
		void Print();
		void Disegna();
		bool laCellaFuori(int riga, int colonna);
		bool laCellaVuota(int riga, int colonna);
		int pulisciTutteRighe();
		int griglia[20][10];

	private:

		bool laRigaPiena(int riga);
		void pulisciRiga(int riga);
		void muoviRigaSotto(int riga, int numRighe);

		int numRighe;
		int numColonne;
		int grandCella;

		std::vector<Color> colori; // creiamo un vettore che contiene oggetti Colore al suo interno, chiamato colori
};