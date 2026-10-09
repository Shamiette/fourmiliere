#pragma once
#include "Agent.h"

// Classe Food qui hérite de la classe Agent
class Food : public Agent {
    private :
    // attributs
    float qte_actuelle ;
    bool a_change = false ;

    public :
        // Constructeur de la classe Food
        Food (Environment* p, const Vector2<float> & position, float qte);

        // Permet de savoir la quantité de nourriture dans le stock de nourriture
        float getFoodQuantity() const ;

        // Permet de récupérer de la Nourriture dans le stock de nourriture
        float collectFood(float qte_actuelle) ;

        // vérifie si la quantité de nourriture a changé, si oui le rayon de l’agent est mis à jour
        // si la quantité de nourriture restante est égale à 0 : l'agent passe e nmode destroy
        // Affiche l'agent Food sous la forme d’un cercle de couleur R : 154, G : 235, B : 38, A : 255
        void update() ;

        // Destructeur de la classe Food
        ~Food();
};