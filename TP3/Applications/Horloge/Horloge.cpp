#include "Horloge.h"
#include "drivers/timer.h"
#include "drivers/Ecran.h"

	/****************************************************/
	/* Question 1 : Implementation de la classe Horloge */
	/****************************************************/
Horloge::Horloge(Ecran* ecr,Timer *timer) {
	lEcran=ecr;
	leTimer=timer;
}


void Horloge::afficheHeure() {
	int secondes = leTimer->getSecondes();
	int minutes = secondes / 60;
	int secondesRestantes = secondes % 60;
	
	int position = (COLONNES - 5) / 2;
	lEcran->afficherNombre(0, position, minutes);

	lEcran->afficherMot(":", BLANC);
	lEcran->afficherNombre(0, position + 2, secondesRestantes);
}
