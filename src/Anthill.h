#pragma once
#include "Agent.h"
#include "MathUtils.h"
#include "Renderer.h"

// Classe Anthill qui hérite de la classe Agent
class Anthill : public Agent {
    private :
    // attributs
    float qte_actuelle_fourmilière ;
    bool a_change = false ;

    public :
        // Constructeur de la classe Anthill
        Anthill (Environment* p, const Vector2<float> & position, float qte);

        // permet aux fourmis de déposer la nourriture qu’elles transportent (qte) dans la fourmilière
        void depositFood(float qte);

        // Affiche un cercle de rayon 10 et de couleur R : 0, G : 0, B : 255, A : 255
        void update() ;

        // Getteur de quantité
        float getQuantity();

        // Setteur de quantité
        void setQuantity(float q);

        // Destructeur de la classe Anthill
        ~Anthill();
};