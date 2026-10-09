#include "Ant.h"

// Constructeur de la classe Ant
Ant::Ant(Environment* p, Anthill * fourmiliere, float qte_phe):AntBasePheromone(p, Vector2<float>::random(), fourmiliere, qte_phe){}

// Met à jour la fourmi plus "fourmis"
void Ant::update(){
    ::AntBase::update();
    // J'ai choisi délibérément d'effectuer les comportements des fourmis qui ne transportent pas de nourriture
    // aux fourmis qui ne transportent pas la quantité de nourriture maximale.
    // En effet lorsque les fourmis ne tranportent pas la quantité optimale cela veut dire que le dépôt de nourriture
    // est épuisé et donc il est logique qu'elles déposent moins de phéromones afin que les autres fourmis n'y aille pas.
    if(getQuantity() < 5){
        // Fourmi sur la nourriture
        if(!perceive<Food>().empty()){
            recolter(*perceive<Food>().front());
        }
        else{
            // Fourmi perçoit de la nourriture
            if(perçue()!=nullptr){
                target(perçue()->getPosition());
                avancer();
            }
            else {
                // Fourmi perçoit des phéromones
                if(choosePheromone()!=nullptr){
                    target(choosePheromone()->getPosition());
                    avancer();
                }
                // Fourmi ne perçoit pas de phéromones
                else{
                    tourner(MathUtils::random(-MathUtils::pi/10* Timer::dt(), MathUtils::pi/10* Timer::dt()));
                    avancer();
                }
            }
        }
        putPheromone(10);
    }
    // La fourmi possède 5 nourritures
    else {
        // Fourmi sur sa fourmilière
        if (!perceive<Anthill>().empty()){
            if(perceive<Anthill>().front()==getAnthill()){
                deposer();
                demi_tour();
            }
        }
        // Fourmi pas sur sa fourmilière
        else {
            target(getAnthill()->getPosition());
            // Fourmi perçoit des pheromones
            if(choosePheromone()!=nullptr){
                target(choosePheromone()->getPosition());
            }
            avancer();
        }
        putPheromone(100);
    }
}

// Destructeur de la classe Ant
Ant::~Ant(){

}