#include "Grille.h"


Grille::Grille(int x0, int y0) {
	x0_ = x0; 
	y0_ = y0; 
}

Grille::~Grille() {
	// Rien 
}

void Grille::afficher(sf::RenderWindow &window) {
	
	sf::Texture image; 
	sf::Sprite carteImage;

	int i; 
	for (i = 0; i < cartes_.size(); i++) {
		if (!image.loadFromFile(cartes_[i]->getNom())) {
			cout << "Dont load image !" << endl; 
		}
		carteImage.setPosition(cartes_[i]->getPositionX(), cartes_[i]->getPositionY());
		carteImage.setTexture(image);

		window.draw(carteImage);
	}

	
}

void Grille::ajouterCarte(Carte *carte) {
	cartes_.push_back(carte);
}

void Grille::setPositionEmpty(int x0, int y0) {
	x0_ = x0; 
	y0_ = y0; 
}

//Vérifier que la caze toucher petu être intervertis avec la caze rouge 
bool Grille::deplacementPossible(int xClique, int yClique) {
	
	// Caze à gauche
	if (xClique < x0_ && xClique > x0_ - 200 && yClique > y0_ && yClique < y0_ + 200) {
		return true; 
	}

	// Caze en haut 
	if (xClique > x0_ && xClique < x0_ + 200 && yClique < y0_ && yClique > y0_ - 200) {
		return true;
	}

	//Caze droite
	if (xClique > x0_+200 && xClique < x0_ + 400 && yClique > y0_ && yClique < y0_ + 200) {
		return true;
	}

	//Caze bas 
	if (xClique > x0_ && xClique < x0_+200 && yClique > y0_ +200 && yClique < y0_ + 400) {
		return true;
	}

	return false; 

}

void Grille::deplacement(bool b, int xClique, int yClique) {
	// Verifie qu'il s'agit d'une caze à coté de la caze rouge 
	if (b == true) {
		int x; 
		int y; 

		// Cas carte à gauche 
		if (xClique < x0_ && xClique > x0_ - 200 && yClique > y0_ && yClique < y0_ + 200) {
			
			cout << "Coordonee de la caze toucher : " << x0_ << "  " << y0_- 200 << endl;

			x = x0_- 200;
			y = y0_; 


			for (int i = 0; i < cartes_.size(); i++) {

				if ((cartes_[i]->getPositionX() == x) && (cartes_[i]->getPositionY() == y)) {
					cout << "Il s'agit de la carte numéro: " << i << endl; 
					cartes_[i]->setPosition(x0_, y0_);
				}

			}
			cartes_[15]->setPosition(x, y); 
				
			x0_ = x; 
			y0_ = y; 
			
		}//  Fin du if caze gauche 

		// Cas carte à haut
		if (xClique > x0_ && xClique < x0_ + 200 && yClique < y0_ && yClique > y0_ - 200) {

			cout << "Coordonee de la caze toucher : " << x0_ << "  " << y0_ - 200 << endl;

			x = x0_;
			y = y0_ - 200;


			for (int i = 0; i < cartes_.size(); i++) {

				if ((cartes_[i]->getPositionX() == x) && (cartes_[i]->getPositionY() == y)) {
					cout << "Il s'agit de la carte numéro: " << i << endl;
					cartes_[i]->setPosition(x0_, y0_);
				}

			}
			cartes_[15]->setPosition(x, y);

			x0_ = x;
			y0_ = y;

		}//  Fin du if caze haut

		// Cas carte à droite 
		if (xClique > x0_ + 200 && xClique < x0_ + 400 && yClique > y0_ && yClique < y0_ + 200) {

			cout << "Coordonee de la caze toucher : " << x0_ + 200 << "  " << y0_ << endl;

			x = x0_ + 200;
			y = y0_;


			for (int i = 0; i < cartes_.size(); i++) {

				if ((cartes_[i]->getPositionX() == x) && (cartes_[i]->getPositionY() == y)) {
					cout << "Il s'agit de la carte numéro: " << i << endl;
					cartes_[i]->setPosition(x0_, y0_);
				}

			}
			cartes_[15]->setPosition(x, y);

			x0_ = x;
			y0_ = y;

		}//  Fin du if caze droite

		// Cas carte en bas 
		if (xClique > x0_ && xClique < x0_ + 200 && yClique > y0_ + 200 && yClique < y0_ + 400) {

			cout << "Coordonee de la caze toucher : " << x0_ << "  " << y0_ + 200 << endl;

			x = x0_ ;
			y = y0_ + 200;


			for (int i = 0; i < cartes_.size(); i++) {

				if ((cartes_[i]->getPositionX() == x) && (cartes_[i]->getPositionY() == y)) {
					cout << "Il s'agit de la carte numero: " << i << endl;
					cartes_[i]->setPosition(x0_, y0_);
				}

			}
			cartes_[15]->setPosition(x, y);

			x0_ = x;
			y0_ = y;

		}//  Fin du if caze droite
	}
}

void Grille::melanger() {

}
