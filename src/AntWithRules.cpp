#include "AntWithRules.h"
#include "OrRule.h"

////////////////////////////////////////////
/////////// classe AntWithRules ////////////
////////////////////////////////////////////

// Constructeur de la classe AntWithRules
AntWithRules::AntWithRules(Environment* p, Anthill * fourmiliere, float qte_phe):AntBasePheromone(p, Vector2<float>::random(), fourmiliere, qte_phe){
    std::vector<AbstractRule*> conditionsNourriture ;
    conditionsNourriture.push_back(new ramasser(this));
    conditionsNourriture.push_back(new deplacerVersNourriture(this));
    conditionsNourriture.push_back(new deplacerVersPheromone(this));
    conditionsNourriture.push_back(new deplacerHasard(this));
    reglesNourritures = new OrRule (conditionsNourriture) ;

    std::vector<AbstractRule*> conditionsFourmiliere ;
    conditionsFourmiliere.push_back(new deposerNourriture(this));
    conditionsFourmiliere.push_back(new trouverNid(this));
    reglesFourmiliere = new OrRule (conditionsFourmiliere) ;
}

void AntWithRules::update(){
    AntBase::update();
    if(getQuantity() == 5){
        reglesFourmiliere->action();
        putPheromone(100);
    }
    else {
        reglesNourritures->action();
        putPheromone(10);
    }
}

// Destructeur de la classe AntWithRules
AntWithRules::~AntWithRules(){
    delete reglesNourritures ;
    delete reglesFourmiliere ;
}

////////////////////////////////////////////
///////////// classe ramasser //////////////
////////////////////////////////////////////

// Constructeur de la classe ramasser
AntWithRules::ramasser::ramasser(AntBasePheromone* f):AbstractAntRule(f){}

// Condition d'exécution : l'entité est positionnée sur de la nourriture
bool AntWithRules::ramasser::condition(){
    if(!fourmi->perceive<Food>().empty()){
        return true;
    }
    return false;
}

// Déclenche l'action de ramasser de la nourriture
void AntWithRules::ramasser::action(){
    fourmi->recolter(*fourmi->perceive<Food>().front());
}

// Destructeur de la classe ramasser
AntWithRules::ramasser::~ramasser(){}

////////////////////////////////////////////
////// classe deplacerVersNourriture ///////
////////////////////////////////////////////

// Constructeur de la classe deplacerVersNourriture
AntWithRules::deplacerVersNourriture::deplacerVersNourriture(AntBasePheromone* f):AbstractAntRule(f){}

// Condition d'exécution : l'entité perçoit de la nourriture
bool AntWithRules::deplacerVersNourriture::condition(){
    if(fourmi->perçue()!=nullptr){
        return true;
    }
    return false;
}

// Déclenche l'action de se déplacer vers de la nourriture
void AntWithRules::deplacerVersNourriture::action(){
    fourmi->target(fourmi->perçue()->getPosition());
    fourmi->avancer();
}

// Destructeur de la classe deplacerVersNourriture
AntWithRules::deplacerVersNourriture::~deplacerVersNourriture(){}

////////////////////////////////////////////
/////// classe deplacerVersPheromone ///////
////////////////////////////////////////////

// Constructeur de la classe deplacerVersPheromone
AntWithRules::deplacerVersPheromone::deplacerVersPheromone(AntBasePheromone* f):AbstractAntRule(f){}

// Condition d'exécution : l'entité perçoit des phéromones
bool AntWithRules::deplacerVersPheromone::condition(){
    if(fourmi->choosePheromone()!=nullptr){
        return true;
    }
    return false;
}

// Déclenche l'action de se déplacer vers des phéromones
void AntWithRules::deplacerVersPheromone::action(){
    fourmi->target(fourmi->choosePheromone()->getPosition());
    fourmi->avancer();
}

// Destructeur de la classe deplacerVersPheromone
AntWithRules::deplacerVersPheromone::~deplacerVersPheromone(){}

////////////////////////////////////////////
////////// classe deplacerHasard ///////////
////////////////////////////////////////////

// Constructeur de la classe deplacerHasard
AntWithRules::deplacerHasard::deplacerHasard(AntBasePheromone* f):AbstractAntRule(f){}

// Condition d'exécution : l'entité ne perçoit ni nourriture ni phéromones 
// (Comme on va utiliser le OrRule qui s'arrête dès qu'une condition est vrai, si on arrive là c'est que les deux condition d'avant étaient
// fausse (percevoir de la nourriture et des pheromones) et donc la condition est toujours respectée)
bool AntWithRules::deplacerHasard::condition(){
    return true ;
}

// Déclenche l'action de se déplacer dans une direction choisie au hasard
void AntWithRules::deplacerHasard::action(){
    fourmi->tourner(MathUtils::random(-MathUtils::pi/10* Timer::dt(), MathUtils::pi/10* Timer::dt()));
    fourmi->avancer();
}

// Destructeur de la classe deplacerHasard
AntWithRules::deplacerHasard::~deplacerHasard(){}

////////////////////////////////////////////
//////// classe deposerNourriture //////////
////////////////////////////////////////////

// Constructeur de la classe deposerNourriture
AntWithRules::deposerNourriture::deposerNourriture(AntBasePheromone* f):AbstractAntRule(f){}

// Condition d'exécution : l'entité est sur son nid
bool AntWithRules::deposerNourriture::condition(){
    if (!fourmi->perceive<Anthill>().empty()){
        if(fourmi->perceive<Anthill>().front()==fourmi->getAnthill()){
            return true ;
        }
    }
    return false ;
}

// Déclenche l'action de déposer la nourriture transportée dans sa fourmilière
void AntWithRules::deposerNourriture::action(){
    fourmi->deposer();
    fourmi->demi_tour();
}

// Destructeur de la classe deposerNourriture
AntWithRules::deposerNourriture::~deposerNourriture(){}

////////////////////////////////////////////
//////////// classe trouverNid /////////////
////////////////////////////////////////////

// Constructeur de la classe trouverNid
AntWithRules::trouverNid::trouverNid(AntBasePheromone* f):AbstractAntRule(f){}

// Condition d'exécution : l'entité n'est pas sur son nid
// (Comme on va utiliser le OrRule qui s'arrête dès qu'une condition est vrai, si on arrive là c'est que la condition d'avant était
// fausse (la fourmie est sur sa fourmilière) et donc la condition est toujours respectée)
bool AntWithRules::trouverNid::condition(){
    return true ;
}

// Déclenche l'action de trouver le nid
void AntWithRules::trouverNid::action(){
    fourmi->target(fourmi->getAnthill()->getPosition());
    // Fourmi perçoit des pheromones
    if(fourmi->choosePheromone()!=nullptr){
        fourmi->target(fourmi->choosePheromone()->getPosition());
    }
    fourmi->avancer();
}

// Destructeur de la classe trouverNid
AntWithRules::trouverNid::~trouverNid(){}