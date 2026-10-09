#include "Factory.h"
#include "AntWithRules.h"

// Constructeur de Factory
Factory::Factory(Anthill * f):fourmiliere(f){}

// Méthode permettant de créer une nouvelle fourmie si il y a au moins 10 de nourriture
void Factory::spawn(Environment* environment){
    float quantity = fourmiliere->getQuantity() ;
    if(quantity >= 10){
        fourmiliere->setQuantity(quantity-10);
        new AntWithRules(environment, fourmiliere, 0);
    }
}

// Destructeur de Factory
Factory::~Factory(){}