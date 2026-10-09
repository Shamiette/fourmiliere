#pragma once
#include "AntBasePheromone.h"

// Classe Pheromone qui hérite de la classe AntBasePheromone
class Ant : public AntBasePheromone {
    private :

    public :
        // Constructeur de la classe Ant
        Ant(Environment* p, Anthill * fourmiliere, float qte_phe);

        // Met à jour la fourmis plus "fourmis"
        void update() override;

        // Destructeur de la classe Ant
        ~Ant();
};