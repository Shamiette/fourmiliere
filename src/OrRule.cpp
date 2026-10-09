#include "OrRule.h"

// Constructeur de la classe OrRule
OrRule::OrRule(std::vector<AbstractRule*> r):regles(r), regleValide(nullptr){}

// Sa condition est vraie si l’une des conditions des règles est vraie
bool OrRule::condition(){
    for (std::vector<AbstractRule*>::const_iterator it = regles.begin() ; it != regles.end(); it++){
        if((*it)->condition() == true){
            regleValide = *it ;
            return true ;
        }
    }
    return false ;
}

// Déclenche l'action pour laquelle la condition est vraie
void OrRule::action(){
    if (condition()){
        regleValide->action();
    }
}

// Destructeur de la classe OrRule
OrRule::~OrRule(){
    for(std::vector<AbstractRule*>::iterator it = regles.begin() ; it != regles.end();){
        AbstractRule * temp = *it;
        it = regles.erase(it);
        delete temp ;
    }
}