#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carte.h"
#include "Grille.h"

using namespace std; 

int main(){
	// Création de la fenêtre SFML
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	window.setKeyRepeatEnabled(false);

	// Création des différentes cartes 
	Carte carte1("image_part_001.jpg", 0, 0);
	Carte carte2("image_part_002.jpg", 200, 0);
	Carte carte3("image_part_003.jpg", 400, 0);
	Carte carte4("image_part_004.jpg", 600, 0);
	Carte carte5("image_part_005.jpg", 0, 200);
	Carte carte6("image_part_006.jpg", 200, 200);
	Carte carte7("image_part_007.jpg", 400, 200);
	Carte carte8("image_part_008.jpg", 600, 200);
	Carte carte9("image_part_009.jpg", 0, 400);
	Carte carte10("image_part_010.jpg", 200, 400); 
	Carte carte11("image_part_011.jpg", 400, 400);
	Carte carte12("image_part_012.jpg", 600, 400);
	Carte carte13("image_part_013.jpg", 0, 600);
	Carte carte14("image_part_014.jpg", 200, 600);
	Carte carte15("image_part_015.jpg", 400, 600);
	Carte carte16("Noir.png", 600, 600); 


	Grille grille;

	
	
	// Ajout à au vect de grille 
	grille.ajouterCarte(&carte1); 
	grille.ajouterCarte(&carte2);
	grille.ajouterCarte(&carte3);
	grille.ajouterCarte(&carte4);
	grille.ajouterCarte(&carte5);
	grille.ajouterCarte(&carte6);
	grille.ajouterCarte(&carte7);
	grille.ajouterCarte(&carte8);
	grille.ajouterCarte(&carte9);
	grille.ajouterCarte(&carte10);
	grille.ajouterCarte(&carte11);
	grille.ajouterCarte(&carte12);
	grille.ajouterCarte(&carte13);
	grille.ajouterCarte(&carte14);
	grille.ajouterCarte(&carte15);
	grille.ajouterCarte(&carte16);
	
    // Position carte rouge 
	grille.setPositionEmpty(carte16.getPositionX(), carte16.getPositionY()); 

	// Le truc pour que la fenêtre reste ouverte 
	while (window.isOpen()){
		
		sf::Event event;
		while (window.pollEvent(event)){
			
			switch (event.type) {
				case sf::Event::Closed():
					window.close(); 
					break; 
			}
		} 

		if (event.mouseButton.button == sf::Mouse::Left) {

			bool b = grille.deplacementPossible(event.mouseButton.x, event.mouseButton.y);
			cout << b << endl; 
			grille.deplacement(b, event.mouseButton.x, event.mouseButton.y);
		}
		
		grille.afficher(window); 
		window.display();
	}
	return 0;
}