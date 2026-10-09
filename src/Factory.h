#pragma once
#include "Anthill.h"

class Factory {
    private :
        Anthill * fourmiliere ;

    public :
        // Constructeur de Factory
        Factory(Anthill * f);

        // Méthode permettant de créer une nouvelle fourmie si il y a au moins 10 de nourriture
        void spawn(Environment* environment);

        // Destructeur de Factory
        ~Factory();
};