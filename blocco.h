#pragma once
#include <vector>
#include <map>
#include "posizione.h"
#include "colori.h"

class Blocco {

	public:
		Blocco();
		void Disegna(int offsetx, int offsety);
		void Movimento(int righe, int colonne);
		std::vector<Posizione> OttieniPosizioneCelle();
		void Ruota();
		void RuotaIndietro();
		int id;
		std::map<int, std::vector<Posizione>> celle;	// creiamo un dizionario (map) che contine il tipo di blocco e un vettore che indica le sue associate da colorare

	private:
	
		int grandezzaCella;
		int statoRotazione;
		
		std::vector<Color> colori;

		int offsetRiga;
		int offsetColonna;
};