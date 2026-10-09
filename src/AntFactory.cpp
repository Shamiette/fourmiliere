#include "AntFactory.h"

// Constructeur de AntFactory
AntFactory::AntFactory(Environment* p, const Vector2<float> & position, float qte): Anthill (p, position, qte){
    factory = new Factory(this);
}

// Met à jour la AntFactory
void AntFactory::update(){
    Anthill::update();
    factory->spawn(getEnvironment());
}

// Destructeur de AntFactory
AntFactory::~AntFactory(){
    delete factory ;
}