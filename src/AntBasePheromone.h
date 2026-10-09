#pragma once
#include "AntBase.h"
#include "Pheromone.h"

// Classe Pheromone qui hérite de la classe AntBase
class AntBasePheromone : public AntBase {
    private :
        float qte_phe_fourmis ;

    public :
        // Constructeur de la classe Pheromone
        AntBasePheromone(Environment* p, const Vector2<float> & dir, Anthill * fourmiliere, float qte_phe);

        // Permet à la fourmi de déposer des phéromones à chaque déplacement
        void putPheromone(float q);

        // Permet de :
        // - (1) de percevoir les phéromones à une distance maximale de 8 cm, 
        // - (2) de choisir au hasard une phéromone à suivre en fonction de sa concentration.
        Pheromone * choosePheromone() const ;

        // Destructeur de la classe Pheromone
        ~AntBasePheromone();
};