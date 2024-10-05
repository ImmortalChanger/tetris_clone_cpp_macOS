#include "gioco.h"
#include <random>

Gioco::Gioco() {

	srand(time(0));

	griglia = Griglia();
	blocchi = ottieniTuttiBlocchi();	// è una funzione per rigenerare un vettore con tutti i blocchi al suo interno
	bloccoCorrente = OttieniBloccoRandom();
	prossimoBlocco = OttieniBloccoRandom();
	gameOver = false;
	punteggio = 0;

	InitAudioDevice();	// inizializziamo l'audio
	musica = LoadMusicStream("audio/music.mp3");	// importiamo il file .mp3
	PlayMusicStream(musica);	// usiamo la funzione play music stream e updatiamo la musica nel main
	
	audioRotazione = LoadSound("audio/rotate.mp3");
	audioRigaPulita = LoadSound("audio/clear.mp3");
}

Gioco::~Gioco() {

	UnloadMusicStream(musica);
	UnloadSound(audioRigaPulita);
	UnloadSound(audioRotazione);
	CloseAudioDevice();
}

Blocco Gioco::OttieniBloccoRandom()
{
	if (blocchi.empty())
	{
		blocchi = ottieniTuttiBlocchi();
	}

	int randomIndex = rand() % blocchi.size();
	Blocco blocco = blocchi[randomIndex];
	blocchi.erase(blocchi.begin() + randomIndex);	// eliminiamo dal vettore il blocco all'indice iniziale + il random scelto
	
	return blocco;
}

std::vector<Blocco> Gioco::ottieniTuttiBlocchi() {

	return { Iblocco(), Jblocco(), Lblocco(), Zblocco(), Oblocco(), Sblocco(), Tblocco() };
}

void Gioco::Disegna() {

	griglia.Disegna();
	bloccoCorrente.Disegna(21, 21); // offset ai blocchi che ci permette di disegnare anche il prossimo blocco
	
	switch(prossimoBlocco.id) {

		case 3:
			prossimoBlocco.Disegna(705 * prop, 735 * prop);	// caso per centrare il blocco I
			break;

		case 4:
			prossimoBlocco.Disegna(705 * prop, 705 * prop);	// caso per centrare il blocco O
			break;

		default:
			prossimoBlocco.Disegna(735 * prop, 695 * prop);	// caso per centrare il resto dei blocchi
			break;
	}

}

void Gioco::gestisciInput() {

	int chiavePremuta = GetKeyPressed();
	if (gameOver && chiavePremuta != 0) {
		gameOver = false;
		Reset();
	}
	switch (chiavePremuta) {

		case KEY_LEFT:
			muoviBloccoSinistra();
			break;

		case KEY_RIGHT:
			muoviBloccoDestra();
			break;

		case KEY_DOWN:
			muoviBloccoSotto();
			break;
		
		case KEY_UP:
			RuotaBlocco();
			break;
		
	}
}

void Gioco::muoviBloccoSinistra() {
	
	if (!gameOver) {
		
		bloccoCorrente.Movimento(0, -1);

		if (ilBloccoFuori() || bloccoAttaccato() == false) {				// verifichiamo se il blocco si trova fuori dopo la mossa, se si, ritorniamo indietro
			bloccoCorrente.Movimento(0, 1);
		}
	}
}
void Gioco::muoviBloccoDestra() {
	
	if (!gameOver) {

		bloccoCorrente.Movimento(0, 1);

		if (ilBloccoFuori() || bloccoAttaccato() == false) {
			bloccoCorrente.Movimento(0, -1);
		}
	}
}
void Gioco::muoviBloccoSotto() {
	
	if (!gameOver) {

		bloccoCorrente.Movimento(1, 0);

		if (ilBloccoFuori() || bloccoAttaccato() == false) {
			bloccoCorrente.Movimento(-1, 0);
			bloccoBloccato();			// che bel gioco di parole, serve per non far più comandare il blocco dall'utente quando tocca il fondo
			aggiornaPunteggio(0, 1);	// aggiungiamo 1 ai blocchi piazzati
		}
	}	
}

void Gioco::bloccoBloccato() {

	std::vector<Posizione> soglie = bloccoCorrente.OttieniPosizioneCelle();
	
	for(Posizione oggetto : soglie){
		griglia.griglia[oggetto.riga][oggetto.colonna] = bloccoCorrente.id;
	}

	bloccoCorrente = prossimoBlocco;
	if (bloccoAttaccato() == false) {

		gameOver = true;
	}
	prossimoBlocco = OttieniBloccoRandom();
	int num = griglia.pulisciTutteRighe();
	
	if (num > 0) {
		PlaySound(audioRigaPulita);
		aggiornaPunteggio(num, 0);
	}

}

bool Gioco::ilBloccoFuori() {
	
	std::vector<Posizione> soglie = bloccoCorrente.OttieniPosizioneCelle();

	for (Posizione oggetto : soglie) {
		
		if (griglia.laCellaFuori(oggetto.riga, oggetto.colonna)) {
			return true;
		}
	}
	return false;
}

void Gioco::RuotaBlocco() {

	if (!gameOver) {

		bloccoCorrente.Ruota();

		if (ilBloccoFuori() || bloccoAttaccato() == false) {
			bloccoCorrente.RuotaIndietro();
		}
		else {
			PlaySound(audioRotazione);
		}
	}
}

bool Gioco::bloccoAttaccato() {	// funzione per verificare se una cella è attaccata ad un'altra già occupata

	std::vector<Posizione> soglie = bloccoCorrente.OttieniPosizioneCelle();

	for (Posizione oggetto : soglie) {

		if (griglia.laCellaVuota(oggetto.riga, oggetto.colonna) == false) {
			return false;
		}
	}
	return true;
}

void Gioco::Reset() {

	griglia.Inizializza();
	blocchi = ottieniTuttiBlocchi();
	bloccoCorrente = OttieniBloccoRandom();
	prossimoBlocco = OttieniBloccoRandom();
	punteggio = 0;
}

void Gioco::aggiornaPunteggio(int righePulite, int puntiMossaBlocco) {

	switch (righePulite) {

		case 1:
			punteggio += 100;
			break;

		case 2:
			punteggio += 300;
			break;

		case 3:
			punteggio += 500;
			break;

		default:
			break;
	}

	punteggio += puntiMossaBlocco;
}

