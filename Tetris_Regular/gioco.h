#pragma once
#include "griglia.h"
#include "blocchi.cpp"

class Gioco {

	public:

		Gioco();
		~Gioco();
		double prop = 0.7;
		void Disegna();
		void gestisciInput();
		void muoviBloccoSotto();
		bool gameOver;
		int punteggio;
		Music musica;

	private:

		Blocco OttieniBloccoRandom();
		Griglia griglia;
		std::vector<Blocco> ottieniTuttiBlocchi();
		void muoviBloccoSinistra();
		void muoviBloccoDestra();
		void bloccoBloccato();
		bool ilBloccoFuori();
		void RuotaBlocco();
		bool bloccoAttaccato();
		void Reset();
		void aggiornaPunteggio(int righePulite, int puntiMossaBlocco);

		std::vector<Blocco> blocchi;
		Blocco bloccoCorrente;
		Blocco prossimoBlocco;

		Sound audioRotazione;
		Sound audioRigaPulita;
};
