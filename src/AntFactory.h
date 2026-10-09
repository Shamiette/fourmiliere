#pragma once
#include "Anthill.h"
#include "Factory.h"

class AntFactory : public Anthill {
    private :
        Factory * factory ;

    public :
        // Constructeur de AntFactory
        AntFactory(Environment* p, const Vector2<float> & position, float qte);

        // Met à jour la AntFactory
        void update() override ;

        // Destructeur de AntFactory
        ~AntFactory();
};