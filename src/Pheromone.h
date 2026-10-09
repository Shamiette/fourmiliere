#pragma once
#include "Agent.h"

// Classe Pheromone qui hérite de la classe Agent
class Pheromone : public Agent {
    private :
        float qte_pheromone_deposee ;

    public :
        // Constructeur de la classe Pheromone
        Pheromone(Environment* p, const Vector2<float> & position, float qte_phe_d);

        // Permet de consulter la quantité de phéromones
        float getQuantity();

        // Permet d'ajouter une quantité q de phéromones à qte_pheromone_deposee
        void addQuantity(float q);

        // Met à jour la quantité de phéromone
        void update();

        // Destructeur de la classe Pheromone
        ~Pheromone();
};