#include "Balle.h"

/**
 * @file Balle.cpp
 * Implémentation des méthodes de la classes Balle et initialisation de id à 0.
 */

Balle::Balle(Grille* laGrille) {

	Random random;

	grille = laGrille;
	vitesse = VITESSE;
	// Choisir une positon aleatoire hors de la zone gris'e :
	y = 1 + random.nextInt(LARGEUR);
	x = 1 + random.nextInt(HAUTEUR);

	// Occuper la case :
	grille->getCase(x,y)->occupe();
	// Choisir un deplacement aleatoire h_d, h_g, b_d, b_g:
	dx = 1 ;  if(random.nextBool()) dx = -dx ;
	dy = 1 ;  if(random.nextBool()) dy = -dy ;
};


void Balle::bouger() {
	//Avancer de (dx, dy) :
	int nx = x + dx ;
	int ny = y + dy ;
	//Deplacement : informer les cases de la presence ou non de la balle :
	grille->getCase(nx,ny)->occupe();
	grille->getCase(x,y)->libere();
	// Nouvelle position :
	x = nx ; y = ny ;
}


bool Balle::avance(){//Retourne false si la balle est perdu

	/****************************************************/
	/* Question 3 : Implementation de la m�thode avance */
	/****************************************************/

	for(int i=0;i<vitesse*50;i++); // hanta anas bddl hadik *50 o dir vitesse li bghiti

	int nx = x + dx;
	int ny = y + dy;
	/* Controler les Collisions avec les bords                                                        */
	if (grille->getCase(nx, ny)->getEtat() == BORD) {
		if (nx == 0 || nx == HAUTEUR - 1) {
		dx = -dx; 
	} else {dy = -dy;}
	}
	if (grille->getCase(nx, ny)->getEtat() == TROU) {
		return false; 
	}
	

	/* la prochaine position de la balle sera en x=x+dx;y=y+dy;                      done                 */

	bouger();

	/* Il faut v�rifier si la balle est en collision ou pas en x+dx et y+dy          done                 */
	/* (se servir des m�thodes getCase et Etat de la classe grille)                  done                 */
	/* si c'est le cas sur un des deux voir les deux, il faut inverser le d�placement done (dx=-dx etc...) */
	/* Une fois mise a jour, d�placez la balle                                                        */
	/* ne pas oublier d'afficher les cases modifi�es                                                   */
	//grille->affiche();
	return true;

}

