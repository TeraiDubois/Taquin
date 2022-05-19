#include "Carte.h"

Carte::Carte(string nom, int x, int y) {
	nom_ = nom; 
	x_ = x; 
	y_ = y; 
}

Carte::~Carte() {
	
}

void Carte::setPosition(int x, int y) {
	x_ = x; 
	y_ = y; 
}


void Carte::setNom(string nom) {
	nom_ = nom; 
}