#pragma once
#include "AntBasePheromone.h"
#include "AbstractAntRule.h"
#include "OrRule.h"

class AntWithRules : public AntBasePheromone {
    private :
        // Liste de règles appliquées lorsque la fourmis cherche de la nourriture
        OrRule * reglesNourritures ;

        // Liste de règles appliquées lorsque la fourmis cherche de sa fourmilière
        OrRule * reglesFourmiliere ;

    public :
        // Constructeur de la classe AntWithRules
        AntWithRules(Environment* p, Anthill * fourmiliere, float qte_phe);

        // Met à jour la fourmi avec des règles
        void update() override ;

        // Destructeur de la classe AntWithRules
        ~AntWithRules();

        class ramasser : public AbstractAntRule {
            public :
                // Constructeur de la classe ramasser
                ramasser(AntBasePheromone* f);

                // Condition d'exécution : l'entité est positionnée sur de la nourriture
                bool condition() override ;

                // Déclenche l'action de ramasser de la nourriture
                void action() override ;

                // Destructeur de la classe ramasser
                ~ramasser();
        };

        class deplacerVersNourriture : public AbstractAntRule {
            public :
                // Constructeur de la classe deplacerVersNourriture
                deplacerVersNourriture(AntBasePheromone* f);

                // Condition d'exécution : l'entité perçoit de la nourriture
                bool condition() override ;

                // Déclenche l'action de se déplacer vers de la nourriture
                void action() override ;

                // Destructeur de la classe deplacerVersNourriture
                ~deplacerVersNourriture();
        };

        class deplacerVersPheromone : public AbstractAntRule {
            public :
                // Constructeur de la classe deplacerVersPheromone
                deplacerVersPheromone(AntBasePheromone* f);

                // Condition d'exécution : l'entité perçoit des phéromones
                bool condition() override ;

                // Déclenche l'action de se déplacer vers des phéromones
                void action() override ;

                // Destructeur de la classe deplacerVersPheromone
                ~deplacerVersPheromone();
        };

        class deplacerHasard : public AbstractAntRule {
            public :
                // Constructeur de la classe deplacerHasard
                deplacerHasard(AntBasePheromone* f);

                // Condition d'exécution : l'entité ne perçoit ni nourriture ni phéromones
                bool condition() override ;

                // Déclenche l'action de se déplacer dans une direction choisie au hasard
                void action() override ;

                // Destructeur de la classe deplacerHasard
                ~deplacerHasard();
        };

        class deposerNourriture : public AbstractAntRule {
            public :
                // Constructeur de la classe deposerNourriture
                deposerNourriture(AntBasePheromone* f);

                // Condition d'exécution : l'entité est sur son nid
                bool condition() override ;

                // Déclenche l'action de déposer la nourriture transportée dans sa fourmilière
                void action() override ;

                // Destructeur de la classe deposerNourriture
                ~deposerNourriture();
        };

        class trouverNid : public AbstractAntRule {
            public :
                // Constructeur de la classe trouverNid
                trouverNid(AntBasePheromone* f);

                // Condition d'exécution : l'entité n'est pas sur son nid
                bool condition() override ;

                // Déclenche l'action de trouver le nid
                void action() override ;

                // Destructeur de la classe trouverNid
                ~trouverNid();
        };
};