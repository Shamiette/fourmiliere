#include "AntBase.h"

// Constructeur de la classe AntBase
AntBase::AntBase(Environment* p, const Vector2<float> & dir, Anthill * fourmiliere, float vitesse): 
Agent(p, fourmiliere->getPosition(), MathUtils::circleRadius(1)), 
qte_tranportee(0), 
v_deplacement(vitesse), 
duree_vie(MathUtils::random(1000,2500)), 
direction(dir.normalized()),
m_fourmiliere(fourmiliere){}

// Méthode permettant à la fourmis d'avancer 
void AntBase::avancer(){
    translate(direction*v_deplacement*Timer::dt());
}

// Méthode permettant à la fourmis de tourner
void AntBase::tourner(float angle){
    direction = direction.rotate(angle);
}

// Méthode permettant de faire demi tour
void AntBase::demi_tour(){
    direction[0] = -direction[0];
    direction[1] = -direction[1];
}

// Méthode permettant de s'orienter vers une cible
void AntBase::target(const Vector2<float> & cible){
    direction = (getPosition()).direction(cible).normalized();
}

// Méthode pour déposer la nourriture que possède la fourmis dans la fourmilière
void AntBase::deposer(){
    m_fourmiliere->depositFood(qte_tranportee);
    qte_tranportee = 0 ;
}

// Méthode pour récolter de la nourriture
// @pre : être sur le dépot de nourriture f
void AntBase::recolter(Food & f){
    if(getPosition().distance(f.getPosition()) <= f.getRadius()){
        float new_qte = f.collectFood(5-qte_tranportee) ;
        qte_tranportee += new_qte ;
    }
}

// Méthode pour percevoir de la nourriture sous certaines conditions :
// - angle d’ouverture de pi/2 radians
// - distance maximale de 3 cm
Food* AntBase::perçue(){
    Environment* e = getEnvironment();
    ::std::vector<Food*> p = e->perceive<Food>(getPosition(), direction, MathUtils::pi, 3);
    if(p.empty()){
        return nullptr;
    }
    return p.front();
}

// Met à jour la base de la fourmis
void AntBase::update(){
    duree_vie -= 1;
    if (duree_vie <= 0){
        detruire();
    }
    Renderer::Color ColorAnt(255, 255, 255, 255);
    if(qte_tranportee>0){
        ColorAnt = Renderer::Color(128, 255, 128, 255);   
    }
    Renderer * f = Renderer::getInstance();
    f->drawCircle(getPosition(), 1, ColorAnt);
}

// Getteur de quantité
float AntBase::getQuantity(){
    return qte_tranportee;
}

// Getteur de la fourmilière
Anthill* AntBase::getAnthill(){
    return m_fourmiliere;
}

// Getteur de la direction
Vector2<float> AntBase::getDirection() const{
    return direction;
}

// Destructeur de la classe AntBase
AntBase::~AntBase(){}