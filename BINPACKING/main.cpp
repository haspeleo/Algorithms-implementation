/*
 * http://www2.algorithm.cs.sunysb.edu/mediawiki/index.php/Introduction-TADM2E //wiki for book Skiena
 * a better way to do this is to use intefaces
 * for diffrenting picking policies
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;


int pickElement(vector<int> v) {
        int size = v.size();
        int index = (rand() % size) + 1;
        return v[index];
    }
int partition(vector<int>&v, int p, int r) {
  int x = v[r];
  int j = p - 1;
  for (int i = p; i < r; i++) {

    if (x >= v[i]) { //ascending order
      j = j + 1;
      int temp = v[j];
      v[j] = v[i];
      v[i] = temp;
    }
  }
  v[r] = v[j + 1];
  v[j + 1] = x;

  return (j + 1);
}


  void quickSort(vector<int>&v, int start, int stop) {
    if (stop > start) {
        int pivot = partition(v, start, stop); //for a better partitionning
        quickSort(v, start, pivot -1);
        quickSort(v, pivot + 1, stop);
    }
}

    vector<int>  binPacking(vector<int> elements, int binSize) {
        vector<int> w;
        quickSort(elements, 0, elements.size() - 1);        
        for(int i = 0; i < elements.size(); i++) {
            //int e = pickElement(elements);
            if( binSize > 0) {                
                binSize = binSize - elements[i];
                w.push_back(elements[i]);
            }
        }
        return w;
    }  
    
    void printVector(vector<int> v) {
        for(int i = 0; i < v.size(); i++) {
        cout <<v[i]<<"  ";
        }
        cout <<""<<endl;
    }

    void permutate() {


    string myints[] = {"E5", "E3", "F3", "F3", "D2",
        "C3", "E1", "C3", "D1", "E2"};

    cout << "The 3! possible permutations with 3 elements:\n";

        sort(myints, myints +9);


     ofstream SaveFile("permutations.txt");

    

    do {
        string output ="les combinaisons here";
        SaveFile << output;
        SaveFile.close();
//        cout << myints[0] << " " << myints[1]
//             << " " << myints[2] << " " << myints[3] << " " <<myints[4]
//             << " " << myints[5] << " " << myints[6] << " " <<myints[7]
//             << " " << myints[8] << " " << myints[9]  <<endl;
//             << " " << myints[8] << " " << myints[9] << " " <<myints[10]<< endl;
    } while (next_permutation(myints, myints + 9));

    }

int main(int argc, char** argv) {
    
    int BIN_SIZE = 6;
    vector<int> set ; //= {1, 2, 5, 9, 10};
    set.push_back(2);
    set.push_back(1);
    set.push_back(9);
    set.push_back(5);
    set.push_back(10);

    permutate();
    printVector(set);

    vector<int> choice  =  binPacking(set, BIN_SIZE);
    printVector(choice);


    return 0;
}

