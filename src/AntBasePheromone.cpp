#include "AntBasePheromone.h"

// Constructeur de la classe Pheromone
AntBasePheromone::AntBasePheromone(Environment* p, const Vector2<float> & dir, Anthill * fourmiliere, float qte_phe):
AntBase(p, dir, fourmiliere),
qte_phe_fourmis(qte_phe){}

// Permet à la fourmi de déposer des phéromones à chaque déplacement
void AntBasePheromone::putPheromone(float q){
    ::std::vector<Pheromone*> ph = LocalizedEntity::perceive<Pheromone>();
    if (!ph.empty()){
        (ph.front())->addQuantity(q);
    }
    else {
        new Pheromone(getEnvironment(), getPosition(), q);
    }
}

// Permet de :
// - (1) de percevoir les phéromones à une distance maximale de 8 cm, 
// - (2) de choisir au hasard une phéromone à suivre en fonction de sa concentration.
Pheromone * AntBasePheromone::choosePheromone() const {
    ::std::vector<Pheromone*> liste_phe = perceive<Pheromone>(getDirection(), MathUtils::pi/2, 8);
    if (liste_phe.empty()){
        return nullptr ;
    }
    std::vector<float> poids_pheromone ;
    for (int i = 0 ; i < liste_phe.size() ; i++){
        poids_pheromone.push_back(liste_phe.at(i)->getQuantity());
    }
    int indicePlusGrandPoids = MathUtils::randomChoose(poids_pheromone);
    return liste_phe[indicePlusGrandPoids];
}

// Destructeur de la classe Pheromone
AntBasePheromone::~AntBasePheromone(){}