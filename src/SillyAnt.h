#pragma once
#include "AntBase.h"

// Classe AntBase qui hérite de la classe Agent
class SillyAnt : public AntBase {
    private :

    public :
        // Constructeur de la classe SillyAnt
        SillyAnt(Environment* p, Anthill * fourmiliere, float vitesse = 1);

        // Met à jour la fourmis "idiote"
        void update() override;

        // Destructeur de la classe SillyAnt
        ~SillyAnt();
};