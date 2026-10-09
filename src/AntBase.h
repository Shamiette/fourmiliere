#pragma once
#include "Agent.h"
#include "Anthill.h"
#include "Food.h"
#include "MathUtils.h"
#include "Renderer.h"

// Classe AntBase qui hérite de la classe Agent
class AntBase : public Agent {
    private :
    // attributs
    Anthill * m_fourmiliere;
    float v_deplacement ;
    Vector2<float> direction ;
    float duree_vie ;
    float qte_tranportee ;

    public :
        // Constructeur de la classe AntBase
        AntBase (Environment* p, const Vector2<float> & dir, Anthill * fourmiliere, float vitesse = 1);

        // Méthode permettant à la fourmis d'avancer 
        void avancer();

        // Méthode permettant à la fourmis de tourner
        void tourner(float angle);

        // Méthode permettant de faire demi tour
        void demi_tour();

        // Méthode permettant de s'orienter vers une cible
        void target(const Vector2<float> & cible);

        // Méthode pour déposer la nourriture que possède la fourmis dans la fourmilière
        void deposer();

        // Méthode pour récolter de la nourriture
        void recolter(Food & f);

        // Méthode pour percevoir de la nourriture sous certaines conditions :
        // - angle d’ouverture de pi/2 radians
        // - distance maximale de 3 cm
        Food* perçue();

        // Met à jour la base de la fourmis
        void update() override;

        // Getteur de quantité
        float getQuantity();

        // Getteur de la fourmilière
        Anthill* getAnthill();

        // Getteur de la direction
        Vector2<float> getDirection() const ;

        // Destructeur de la classe AntBase
        ~AntBase();
};