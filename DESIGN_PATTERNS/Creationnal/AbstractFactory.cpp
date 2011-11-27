/*
 La fabrique détermine le type de l'objet concret qu'il faut créer, et c'est ici que l'objet est effectivement créé (dans le cas du C++, c'est l'instruction new). Cependant, la fabrique retourne un pointeur abstrait sur l'objet concret créé.
Le code client est ainsi isolé de la création de l'objet en l'obligeant à demander à une fabrique de créer l'objet du type abstrait désiré et de lui en retourner le pointeur.
Comme la fabrique retourne uniquement un pointeur abstrait, le code client qui sollicite la fabrique ne connaît pas et n'a pas besoin de connaître le type concret précis de l'objet qui vient d'être créé. Cela signifie en particulier que :
Le code client n'a aucune connaissance du type concret, et ne nécessite donc aucun fichier header ou déclaration de classe requis par le type concret. Le code client n'interagit qu'avec la classe abstraite. Les objets concrets sont en effet créés par la fabrique, et le code client ne les manipule qu'avec leur interface abstraite.
L'ajout de nouveaux types concrets dans le code client se fait en spécifiant l'utilisation d'une fabrique différente, modification qui concerne typiquement une seule ligne de code (une nouvelle fabrique crée des objets de types concrets différents, mais renvoie un pointeur du même type abstrait, évitant ainsi de modifier le code client). C'est beaucoup plus simple que de modifier chaque création de l'objet dans le code client. Si toutes les fabriques sont stockées de manière globale dans un singleton et que tout le code client utilise ce singleton pour accéder aux fabriques pour la création d'objets, alors modifier les fabriques revient simplement à modifier l'objet singleton.
 */





#include <iostream>


using namespace std;

class Shape {
  public:
    Shape() {
      id_ = total_++;
    }
    virtual void draw() = 0;
  protected:
    int id_;
    static int total_;
};
int Shape::total_ = 0;

class Circle : public Shape {
  public:
    void draw() {
      cout << "circle " << id_ << ": draw" << endl;
    }
};

class Square : public Shape {
  public:
    void draw() {
      cout << "square " << id_ << ": draw" << endl;
    }
};

class Ellipse : public Shape {
  public:
    void draw() {
      cout << "ellipse " << id_ << ": draw" << endl;
    }
};

class Rectangle : public Shape {
  public:
    void draw() {
      cout << "rectangle " << id_ << ": draw" << endl;
    }
};

class Factory {
  public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory {
  public:
    Shape* createCurvedInstance() {
      return new Circle;
    }
    Shape* createStraightInstance() {
      return new Square;
    }
};
class RobustShapeFactory : public Factory {
  public:
    Shape* createCurvedInstance()   {
      return new Ellipse;
    }
    Shape* createStraightInstance() {
      return new Rectangle;
    }
};

int main( int, char ** ) {

#ifdef SIMPLE
  Factory* factory = new SimpleShapeFactory;
#elif ROBUST
  Factory* factory = new RobustShapeFactory;
#endif
  Shape* shapes[3];

  shapes[0] = factory->createCurvedInstance();   // shapes[0] = new Ellipse;
  shapes[1] = factory->createStraightInstance(); // shapes[1] = new Rectangle;
  shapes[2] = factory->createCurvedInstance();   // shapes[2] = new Ellipse;

  for (int i=0; i < 3; i++) {
    shapes[i]->draw();
  }

return 0;
}
