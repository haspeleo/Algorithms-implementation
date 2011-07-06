
#include<iostream>
#include<cmath>
using namespace std;

#define PI 3.14
class Forme {
public:
    Forme() {
        sePresenter();
    }
    virtual void sePresenter() const {
        cout<<"Je suis une forme"<<endl;
    }
    virtual ~Forme() {
        cout <<"Destructeur de Forme !"<<endl;
    }
    virtual double surface() const = 0;
};

class Cercle : public Forme {
public:
    Cercle():Forme() {};
    Cercle(int rayon) {
        this->rayon = rayon;
    }
    virtual void sePresenter() const {
        cout<<"Je suis un cercle de rayon = "<<rayon<<endl;
    }
    virtual ~Cercle() {
        cout <<"Destructeur de Cercle ! "<<endl;
    }
    virtual double surface() const {
        return rayon * rayon * PI;
        
    }
private:
    int rayon;
};

class Carre : public Forme {
public:
    Carre() {};
    Carre(int cote) {
        this->cote = cote;
    }
    virtual void sePresenter() const {
        cout<<"Je suis un carre de cote = "<<cote<<endl;
    }
    virtual ~Carre() {
        cout <<"Destructeur de Carre ! "<<endl;
    }
    virtual double surface() const {
        return cote * cote;
    }
private:
    int cote;
};

void afficher(const Forme& x) {
    x.sePresenter();
}
int main(int argc, char** argv) {

    
//    Forme *forme(new Cercle());
//    forme->sePresenter();

    Cercle *cercle(new Cercle(2));
    double s;
    cercle->sePresenter();
    s = cercle->surface();

    cout <<"Surface = "<<s<<endl;
    
    delete cercle;


    Cercle c2(5);
    c2.sePresenter();
    double s2 = c2.surface();
    cout <<"S2 = "<<s2<<endl;
    return 0;
}

