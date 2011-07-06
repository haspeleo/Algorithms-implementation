#include <cstdlib>
#include<iostream>
#include <vector>

using namespace std;


template<typename Type1, typename Type2> Type2 calculerSomme (Type1 operande1, Type2 operande2) {
    Type2 result = operande1 + operande2;
    return result;
}


template  <typename Type1, typename Type2> Type1 max(const Type1& a, const Type2& b) {
    return (a > b) ? a:b;
}

/*moyenne using vectors -- much elegant*/

//template <typename T, typename S> S moyenne(const std::vector<T>& v) {
//    S somme(0);
//    for (int i(0); i < v.size(); i++) {
//        somme += v[i];
//    }
//    return somme / v.size();
//}
/*moyenne using arrays*/
template<typename T, typename S> S moyenne(T tab[], int taille) {
    S somme(0);
    for (int i(0); i < taille; ++i) {
        somme += tab[i];
    }
    return somme / taille;
}

template <typename T> T zero() {
    return 0;
}

int main(int argc, char** argv) {

    int x = 10, y = 2;
    int q = 0;
    q = calculerSomme(x, y);
    cout <<"Somme integer : "<<q<<endl;
    
    float n = 3.2, p = 5.1;
    float r = calculerSomme(n, p);
    cout <<"Somme float : "<<r<<endl;

    float e1 = 3.2; int e2 = 5.1;
    float r1 = calculerSomme(e1, e2);
    cout <<"Somme ambigue : "<<r<<endl;

    double pi = 3.14, e = 2.71;
    cout <<"Max (doubles) = "<<max(pi, e)<<endl;
    int cave = -1, dernierEtage = 12;
    cout <<"Max (integers) = "<<max(cave,dernierEtage)<<endl;
    unsigned int a(43);
    unsigned int b(87);
    cout <<"Max (unsigned) = "<<max(a, b)<<endl;
    cout  <<"Max(drame) = "<<max(pi, dernierEtage)<<endl;
    
    vector<int> vec;
    vec.push_back(7);
    vec.push_back(12);
    vec.push_back(11);
    vec.push_back(19);
    
    cout <<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<" "<<vec[3];
   
    //cout<<"Moyenne = "<<moyenne(vec)<<endl;
    cout <<"Verif moy: "<<(1+2+3+4+5+6+7+8+9)/10<<endl;

    int tab [] = {1, 1, 2, 2, 2};
    cout <<"Moyenne exacte = "<<moyenne<int, double>(tab, 5)<<endl;
    int v  = zero<int>();
    double w = zero<double>();
    return 0;
}

