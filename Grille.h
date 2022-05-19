#ifndef Grille_h
#define Grille_h

#include "Carte.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>


class Grille {
	vector <Carte*> cartes_; 
	int x0_; 
	int y0_;

public:
	Grille(int x0 = 0, int y0 = 0);
	~Grille(); 
	void afficher(sf::RenderWindow &window);
	void setPositionEmpty(int x0, int y0);
	int getPositionEmptyX() { return x0_; };
	int getPositionEmptyY() { return y0_;  };
	bool deplacementPossible(int xClique, int yClique );
	void ajouterCarte(Carte* carte);
	void deplacement(bool b, int xClique, int yClique);
	void melanger(); 
};


#endif
