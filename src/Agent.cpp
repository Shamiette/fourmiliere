#include "Agent.h"

std::set<Agent*> Agent::p_agents;

// Constructeur de la classe agent
Agent::Agent (Environment* p, const Vector2<float> & position, float rayon) : LocalizedEntity(p, position, rayon){
    p_agents.insert(this);
    etat_actuel = running;
}

// Permet d'obtenir le statut de l'agent ( running ou destroy )
Agent::Status Agent::getStatus(){
    return etat_actuel ;
}

// Permet de définir le statut de l'agent à s ( avec s = running ou destroy )
void Agent::setStatus(Agent::Status s){
    etat_actuel = s ;
}

// Détruit un agent de la liste p_agent en mettant son statut à destroy
void Agent::detruire(){
    setStatus(destroy);
}

// parcourt tous les agents
// - Si il est dans l'état running sa méthode update est appelée
// - Si il est dans l'état destroy cela détruit l'agent
void Agent::simulate() {
    for (std::set<Agent*>::iterator it = p_agents.begin() ; it != p_agents.end();){
        if ((*it)->getStatus() == running){
            (*it)->update();
            ++it ;
        }
        else {
            Agent * temp = *it;
            it = p_agents.erase(it);
            delete temp ;
        }
    } 
}

// détruire tous les agents encore actifs en fin de la simulation
void Agent::finalize() {
    while (! p_agents.empty()){
        Agent * temp = *p_agents.begin();
        p_agents.erase(p_agents.begin());
        delete temp ;
    }
}

// Destructeur de la classe agent
Agent::~Agent(){}