#pragma once
#include "AbstractRule.h"

class OrRule : public AbstractRule {
    private :
        std::vector<AbstractRule*> regles ;
        AbstractRule* regleValide ;

    public :
        // Constructeur de la classe OrRule
        OrRule(std::vector<AbstractRule*> r);

        // Sa condition est vraie si l’une des conditions des règles est vraie
        bool condition() override ;

        // Déclenche l'action pour laquelle la condition est vraie
        void action() override ;

        // Destructeur de la classe OrRule
        ~OrRule();
};