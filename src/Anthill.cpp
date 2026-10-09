#include "Anthill.h"

// Constructeur de la classe Anthill
Anthill::Anthill (Environment* p, const Vector2<float> & position, float qte): Agent(p, position, MathUtils::circleRadius(10)), qte_actuelle_fourmilière(0){}

// permet aux fourmis de déposer la nourriture qu’elles transportent (qte) dans la fourmilière
void Anthill::depositFood(float qte){
    a_change = true ;
    qte_actuelle_fourmilière += qte ;
}

// Affiche un cercle de rayon 10 et de couleur R : 0, G : 0, B : 255, A : 255
void Anthill::update(){
    const Renderer::Color ColorFood(0, 0, 255, 255);
    Renderer * f = Renderer::getInstance();
    f->drawCircle(getPosition(), 10, ColorFood);
}

// Getteur de quantité
float Anthill::getQuantity(){
    return qte_actuelle_fourmilière ;
}

// Setteur de quantité
void Anthill::setQuantity(float q){
    qte_actuelle_fourmilière = q ;
}

// Destructeur de la classe Anthill
Anthill::~Anthill(){}