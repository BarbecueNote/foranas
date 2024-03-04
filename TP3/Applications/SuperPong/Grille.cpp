#include "Grille.h"


Grille::Grille(){
}


Grille::Grille(Ecran* e){
	//Initialisation de la grille
	for(int x=0 ; x<HAUTEUR ; x++) {
		for(int y=0 ; y<LARGEUR ; y++) {
			tab[x][y].init(x,y);
			tab[x][y].setEcran(e);
			if(x==0 || x==(HAUTEUR-1))//Installation des bords
				tab[x][y].setCaseBord();
			if(y==0)
				if(x > HAUTEUR/3 && x< HAUTEUR*2/3)
					tab[x][y].setCaseTrou();//Installation du trou � gauche
				else
					tab[x][y].setCaseBord();
			if(y==(LARGEUR-1))
				if(x > HAUTEUR/3 && x< HAUTEUR*2/3)
					tab[x][y].setCaseTrou();//Installation du trou � droite
				else
					tab[x][y].setCaseBord();

		}
	}
	initRaquette(3,4);
};

void Grille::init(Ecran* e){
	//Initialisation de la grille
	for(int x=0 ; x<HAUTEUR ; x++) {
		for(int y=0 ; y<LARGEUR ; y++) {
			tab[x][y].init(x,y);
			tab[x][y].setEcran(e);
			if(x==0 || x==(HAUTEUR-1))//Installation des bords
				tab[x][y].setCaseBord();
			if(y==0)
				if(x > HAUTEUR/3 && x< HAUTEUR*2/3)
					tab[x][y].setCaseTrou();//Installation du trou � gauche
				else
					tab[x][y].setCaseBord();
			if(y==(LARGEUR-1))
				if(x > HAUTEUR/3 && x< HAUTEUR*2/3)
					tab[x][y].setCaseTrou();//Installation du trou � droite
				else
					tab[x][y].setCaseBord();

		}
	}
	initRaquette(3,4);
};

void Grille::monterRaquette(int gd){
	if (gd == GAUCHE) {
		if (raqg.getHaut() > 1) {
			tab[raqg.getHaut()-1][raqg.getY()].setCaseBord();
			tab[raqg.getHaut()-1][raqg.getY()].paint();
			tab[raqg.getBas()][raqg.getY()].setCaseVide();
			tab[raqg.getBas()][raqg.getY()].paint();
			raqg.monter();
		}
	} else if (gd == DROITE) {
		if (raqd.getHaut() > 1) {
			tab[raqd.getHaut()-1][raqd.getY()].setCaseBord();
			tab[raqd.getHaut()-1][raqd.getY()].paint();
			tab[raqd.getBas()][raqd.getY()].setCaseVide();
			tab[raqd.getBas()][raqd.getY()].paint();
			raqd.monter();
		}
	}
}

void Grille::descendreRaquette(int gd){
	if (gd == GAUCHE) {
		if (raqg.getBas()  < HAUTEUR - 2) {
			tab[raqg.getHaut()][raqg.getY()].setCaseVide();
			tab[raqg.getHaut()][raqg.getY()].paint();
			tab[raqg.getBas()+1][raqg.getY()].setCaseBord();
			tab[raqg.getBas()+1][raqg.getY()].paint();
			raqg.descendre();
		}
	} else if (gd == DROITE) {
		if (raqd.getBas() < HAUTEUR - 2) {
			tab[raqd.getHaut()][raqd.getY()].setCaseVide();
			tab[raqd.getHaut()][raqd.getY()].paint();
			tab[raqd.getBas()+1][raqd.getY()].setCaseBord();
			tab[raqd.getBas()+1][raqd.getY()].paint();
			raqd.descendre();
		}
	}
}

void Grille::initRaquette(int y,int lg){ // colonne, taille

	raqg.init(lg,y);
	raqd.init(lg,LARGEUR -1 - y);

	for(int i=0;i<=lg;i++) {
		tab[raqg.getHaut()+i][raqg.getY()].setCaseBord();
		tab[raqd.getHaut()+i][raqd.getY()].setCaseBord();
	}
}

Case* Grille::getCase(int x,int y) {
	return &tab[x][y];
}

void Grille::affiche(){
	for (int x=0 ; x<HAUTEUR ; x++) {
		for (int y=0 ; y<LARGEUR ; y++) {
			tab[x][y].paint();
		}
	}
};
