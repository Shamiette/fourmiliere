#include "SillyAnt.h"

// Constructeur de la classe SillyAnt
SillyAnt::SillyAnt(Environment* p, Anthill * fourmiliere, float vitesse):
AntBase(p, Vector2<float>::random(), fourmiliere){}

// Met à jour la fourmis "idiote"
void SillyAnt::update(){
    ::AntBase::update();
    if (getQuantity() < 5){
        tourner(MathUtils::random(-MathUtils::pi/10* Timer::dt(), MathUtils::pi/10* Timer::dt()));
    }
    else {
       target(getAnthill()->getPosition());
    }
    avancer();
    if (!perceive<Anthill>().empty()){
        deposer();
    }
    if (!perceive<Food>().empty()){
        recolter(*perceive<Food>().front());
    }
}

// Destructeur de la classe SillyAnt
SillyAnt::~SillyAnt(){}