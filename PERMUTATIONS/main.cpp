/*
 * http://www.codeguru.com/cpp/cpp/algorithms/article.php/c5123 --permutation
 * http://stattrek.com/Tools/EventCounter.aspx -- probabilities
 * http://www.mathsisfun.com/combinatorics/combinations-permutations.html --fun math
 */

#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T, typename Func>
void vector_permutation(std::vector<T>& now, std::vector<T> next, Func func) {
    int size = now.size();
    if (size > 0) {
        for (int cnt = 0; cnt < size; ++cnt) {
            std::vector<T> vt;

            //std::vector<T>::const_iterator it;
            typename  std::vector<T>::const_iterator it;
            it = now.begin();
            for (int cnt1 = 0; cnt1 < size; ++cnt1) {
                if (cnt1 == cnt) {
                    ++it;
                    continue;
                } else
                    vt.push_back(*it);
                ++it;
            }

            typename std::vector<T>::const_iterator it1;
            it1 = now.begin();
            --it1;
            for (int cnt2 = 0; cnt2 <= cnt; ++cnt2) {
                ++it1;
            }

            next.push_back(*it1);
            vector_permutation(vt, next, func);
            next.pop_back();
        }

    }
    else {
        func(next);
    }
}

//using iterators

//void display(vector<char> perm) {
//    for (vector<char>::iterator it = perm.begin(); it != perm.end(); ++it)
//        cout << *it;
//    cout << endl;
//}
template <typename T>
void display(vector<T> perm) {
    for (typename vector<T>::iterator it = perm.begin(); it != perm.end(); ++it)
        cout << *it;
    cout << endl;
}

void string_permutation(std::string& orig, std::string& perm) {
    if (orig.empty()) {
        std::cout << perm << std::endl;
        return;
    }

    for (int i = 0; i < orig.size(); ++i) {
        std::string orig2 = orig;
        orig2.erase(i, 1);
        std::string perm2 = perm;
        perm2 += orig.at(i);
        string_permutation(orig2, perm2);
    }
}

int main() {
    std::string orig = "ABCDE";
    std::string perm;

    cout << "Permutations " << endl;
    string_permutation(orig, perm);

    
    cout << "Template Permutations" << endl;

    vector<string> v;
    vector<string> w;

    v.push_back("A");
    v.push_back("B");
    v.push_back("C");
    v.push_back("D");
    v.push_back("E");

    vector_permutation(v, w, display<string>);


    return 0;
}



////////////////////////////////////////////////////::
//#include <iostream.h>
//#include <conio.h>
//#include <stdio.h>
//#include <string.h>
//using namespace std;
//
//class Permutation
//{
//  private:
//    static char s[20];
//    int width,l;
//  public:
//    void input();
//    void compute();
//    void recur(char choice[],char final[],int);
//};
//char Permutation::s[20];
//
//void Permutation::input()
//{
//  cout<<"Enter the string:";
//  gets(s);
//  cout<<"Places to arrange:";
//  cin>>width;
//};
//
//void Permutation::compute()
//{
//  l=strlen(s);
//  char s1[20];
//  recur(s,s1,0);
//}
//
//void Permutation::recur(char choice[],char final[],int p)
//{
//   int i,j,chk,c=0;
//   if(p==width){//base condition
//     cout<<"OUT: "<<final;
//	 cout<<endl;
//	 return;
//   }
//   //setting choice variables
//   for(i=0;i<l;i++){
//   	   chk=0;
//       for(j=0;j<strlen(final);j++){
//
//	     	 if(s[i]==final[j])
//		       chk=1;
//       }
//	   if(chk==0){choice[c++]=s[i];}
//   }
//   choice[c]='\0';
//
//  //traversing recursion
//  for(i=0;i<c-1;i++){
//
//	final[p]=choice[i];
//	final[p+1]='\0';cout<<"Beforein:\t "<<choice<<" -\t "<<final<<" -\t "<<p+1<<" -\t"<<i+1<<" "<<c<<endl<<endl;
//	recur(choice,final,p+1);
//
//	cout<<"Returned: \t"<<choice<<" - \t"<<final<<" - \t"<<p+1<<"-\t"<<i+1<<" "<<c<<endl<<endl;
//  }
//}
//
//int main()
//{
//   Permutation arrange;
//   arrange.input();
//   arrange.compute();
//   getch();
//   return 0;
//}