#ifndef Carte_h
#define Carte_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;


class Carte {
	string nom_; 
	int x_;
	int y_; 
public:
	Carte(string nom = " ", int x = 0, int y = 0);
	~Carte(); 
	int getPositionX() { return x_;  };
	int getPositionY() { return y_; };
	string getNom() { return nom_; };
	void setPosition(int x, int y); 
	void setNom(string nom);
};

#endif
