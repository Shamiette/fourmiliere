#include "Pheromone.h"

// Constructeur de la classe Pheromone
Pheromone::Pheromone(Environment* p, const Vector2<float> & position, float qte_phe_d):
Agent(p, position, 1),
qte_pheromone_deposee(qte_phe_d){}

// Permet de consulter la quantité de phéromones
float Pheromone::getQuantity(){
    return qte_pheromone_deposee ;
}

// Permet d'ajouter une quantité q de phéromones à qte_pheromone_deposee
void Pheromone::addQuantity(float q){
    qte_pheromone_deposee += q ;
}

// Met à jour la quantité de phéromone
void Pheromone::update(){
    qte_pheromone_deposee -= 0.01*qte_pheromone_deposee*Timer::dt();
    if (qte_pheromone_deposee<0.01){
        detruire();
    }
    float A = std::min<float>(getQuantity(),255);
    Renderer::Color ColorPhe(0, 128, 128, A);
    Renderer * f = Renderer::getInstance();
    f->drawCircle(getPosition(), 1, ColorPhe);
}

// Destructeur de la classe Pheromone
Pheromone::~Pheromone(){}