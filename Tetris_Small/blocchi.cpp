#include "blocco.h"
#include "posizione.h"

class Lblocco : public Blocco{	// il blocco L inerita dalla classe Blocco genitore

	public:
		Lblocco() {

			id = 1;
			celle[0] = { Posizione(0, 2), Posizione(1, 0), Posizione(1, 1), Posizione(1, 2) };
			celle[1] = { Posizione(0, 1), Posizione(1, 1), Posizione(2, 1), Posizione(2, 2) };
			celle[2] = { Posizione(1, 0), Posizione(1, 1), Posizione(1, 2), Posizione(2, 0) };
			celle[3] = { Posizione(0, 0), Posizione(0, 1), Posizione(1, 1), Posizione(2, 1) };
			Movimento(0, 3);
		}

};

class Jblocco : public Blocco {

	public:
		Jblocco() {

			id = 2;
			celle[0] = { Posizione(0, 0), Posizione(1, 0), Posizione(1, 1), Posizione(1, 2) };
			celle[1] = { Posizione(0, 1), Posizione(0, 2), Posizione(1, 1), Posizione(2, 1) };
			celle[2] = { Posizione(1, 0), Posizione(1, 1), Posizione(1, 2), Posizione(2, 2) };
			celle[3] = { Posizione(0, 1), Posizione(1, 1), Posizione(2, 0), Posizione(2, 1) };
			Movimento(0, 3);
		}

};

class Iblocco : public Blocco {	

	public:
		Iblocco() {

			id = 3;
			celle[0] = { Posizione(1, 0), Posizione(1, 1), Posizione(1, 2), Posizione(1, 3) };
			celle[1] = { Posizione(0, 2), Posizione(1, 2), Posizione(2, 2), Posizione(3, 2) };
			celle[2] = { Posizione(2, 0), Posizione(2, 1), Posizione(2, 2), Posizione(2, 3) };
			celle[3] = { Posizione(0, 1), Posizione(1, 1), Posizione(2, 1), Posizione(3, 1) };
			Movimento(-1, 3);
		}

};

class Oblocco : public Blocco {

	public:
		Oblocco() {

			id = 4;
			celle[0] = { Posizione(0, 0), Posizione(0, 1), Posizione(1, 0), Posizione(1, 1) };
			Movimento(0, 4);
		}

};

class Sblocco : public Blocco {

	public:
		Sblocco() {

			id = 5;
			celle[0] = { Posizione(0, 1), Posizione(0, 2), Posizione(1, 0), Posizione(1, 1) };
			celle[1] = { Posizione(0, 1), Posizione(1, 1), Posizione(1, 2), Posizione(2, 2) };
			celle[2] = { Posizione(1, 1), Posizione(1, 2), Posizione(2, 0), Posizione(2, 1) };
			celle[3] = { Posizione(0, 0), Posizione(1, 0), Posizione(1, 1), Posizione(2, 1) };
			Movimento(0, 3);
		}

};

class Tblocco : public Blocco {

	public:
		Tblocco() {

			id = 6;
			celle[0] = { Posizione(0, 1), Posizione(1, 0), Posizione(1, 1), Posizione(1, 2) };
			celle[1] = { Posizione(0, 1), Posizione(1, 1), Posizione(1, 2), Posizione(2, 1) };
			celle[2] = { Posizione(1, 0), Posizione(1, 1), Posizione(1, 2), Posizione(2, 1) };
			celle[3] = { Posizione(0, 1), Posizione(1, 0), Posizione(1, 1), Posizione(2, 1) };
			Movimento(0, 3);
		}

};

class Zblocco : public Blocco {

	public:
		Zblocco() {

			id = 7;
			celle[0] = { Posizione(0, 0), Posizione(0, 1), Posizione(1, 1), Posizione(1, 2) };
			celle[1] = { Posizione(0, 2), Posizione(1, 1), Posizione(1, 2), Posizione(2, 1) };
			celle[2] = { Posizione(1, 0), Posizione(1, 1), Posizione(2, 1), Posizione(2, 2) };
			celle[3] = { Posizione(0, 1), Posizione(1, 0), Posizione(1, 1), Posizione(2, 0) };
			Movimento(0, 3);
		}

};