#pragma once
#include "AbstractRule.h"
#include "AntBasePheromone.h"

class AbstractAntRule : public AbstractRule {
    protected :
        AntBasePheromone * fourmi ;

    public :
        // Constructeur de la classe AbstractAntRule
        AbstractAntRule(AntBasePheromone* f);

        // Destructeur de la classe AbstractAntRule
        ~AbstractAntRule();
};