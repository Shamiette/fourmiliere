#pragma once
#include "Environment.h"
#include <iostream>
#include "Timer.h"
#include "MathUtils.h"
#include "Renderer.h"

// Classe Agent qui hérite de Environment::LocalizedEntity
class Agent : public Environment::LocalizedEntity {
    // attributs
    protected :
        typedef enum { running, destroy } Status ;
        static std::set<Agent*> p_agents ;

    private :
        Status etat_actuel ;

    public :
        // Constructeur de la classe agent
        Agent (Environment* p, const Vector2<float> & position, float rayon = defaultRadius());

        // Implémente, par héritage, le comportement de l’agent.
        // Permet à l’agent de réaliser des actions telles qu’un déplacement, ramasser
        // de la nourriture etc…
        virtual void update() = 0 ;

        // Permet d'obtenir le statut de l'agent ( running ou destroy )
        Status getStatus() ;

        // Permet de définir le statut de l'agent à s ( avec s = running ou destroy )
        void setStatus(Status s) ;

        // Détruit un agent de la liste p_agent en mettant son statut à destroy
        void detruire();

        // parcourt tous les agents
        // - Si il est dans l'état running sa méthode update est appelée
        // - Si il est dans l'état destroy cela détruit l'agent
        static void simulate() ;

        // détruire tous les agents encore actifs en fin de la simulation
        static void finalize() ;

        // Destructeur de la classe agent
        ~Agent(); 
};