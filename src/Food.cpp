#include "Food.h"

// Constructeur de la classe Food
Food::Food (Environment* p, const Vector2<float> & position, float qte): Agent(p, position, MathUtils::circleRadius(qte)), qte_actuelle(qte){}

// Permet de savoir la quantité de nourriture dans le stock de nourriture
float Food::getFoodQuantity() const {
    return qte_actuelle ;
}

// Permet de récupérer de la Nourriture dans le stock de nourriture
float Food::collectFood(float qte) {
    a_change = true ;
    if(qte <= qte_actuelle){
        qte_actuelle -= qte ;
        return qte ;
    }
    else {
        float tmp = qte_actuelle;
        qte_actuelle = 0;
        return tmp;
    }
}

// vérifie si la quantité de nourriture a changé, si oui le rayon de l’agent est mis à jour
// si la quantité de nourriture restante est égale à 0 : l'agent passe e nmode destroy
// Affiche l'agent Food sous la forme d’un cercle de couleur R : 154, G : 235, B : 38, A : 255
void Food::update() {
    if (qte_actuelle == 0){
        detruire();
    }
    if (a_change == true){
        setRadius(MathUtils::circleRadius(qte_actuelle));
        a_change = false ;
    }
    const Renderer::Color ColorFood(154, 235, 38, 255);
    Renderer * f = Renderer::getInstance();
    f->drawCircle(getPosition(), getRadius(), ColorFood);
}

// Destructeur de la classe Food
Food::~Food(){}