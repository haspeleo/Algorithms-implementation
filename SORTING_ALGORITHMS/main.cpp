/* 
 * http://www.codecodex.com/wiki/Insertion_sort
 * http://courses.cs.vt.edu/cs3114/Spring11/Assign.php
 * http://courses.cs.vt.edu/~csonline/Algorithms/Lessons/index.html
 * http://www.snippets.24bytes.com/2010/06/selection-sort.html
 * http://courses.csail.mit.edu/iap/interview/materials.php //Questions for interviews
 * http://sites.google.com/site/steveyegge2/five-essential-phone-screen-questions
 * http://google-interview.com/google-interview/
 * http://www.codeproject.com/KB/threads/Parallel_Quicksort.aspx
 */

#include <cstdlib>
#include<vector>
#include<iostream>

#include<algorithm>
#include<iterator>
#include<functional>

#include "Timer.h"


using namespace std;


/*Here some helper functions*/

void insertElement(vector<int> &v, int element, int position) {
    vector<int> w;
    for(int i = 0; i < position; i++) {
        w.push_back(v[i]);
    }
    w.push_back(element);
    for(int i = position; i < v.size(); i++) {
        w.push_back(v[i]);
    }
    v = w;
}

void printVector(vector<int> &v) {
    for(int i = 0; i < v.size(); ++i) {
        cout <<v[i]<<" ";
    }
    cout <<" "<<endl;
}


void fillVectorSemiRandomly(vector<int> &v, int dataSize) {

    int middle = (dataSize % 2 == 0) ? dataSize / 2 : dataSize / 2 + 1 ;
    srand((unsigned)time(0));
    int randomNumber;
    for(int i = 0; i < middle; i++) {
        v.push_back(i);
    }
    for(int i = middle + 1 ; i < dataSize ; i++) {
        randomNumber = rand() % dataSize + 1;
        v.push_back(randomNumber);
    }

}
void fillVectorSorted(vector<int> &v, int dataSize) {
    for(int i = 0; i < dataSize; i++) {
        v.push_back(i);
    }
}
void fillVectorRandomly(vector<int> &v, int dataSize) {
    srand((unsigned)time(0));
    int randomNumber;
    for(int i = 0; i < dataSize; i++) {
        randomNumber = rand() % dataSize + 1;
        v.push_back(randomNumber);
    }
}

void copyVector(vector<int>&source, vector<int>&destination, int start, int end) {
   
    for(int i = start; i < end; i++) {
        destination.push_back(source[i]);        
    }
}

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    // Fill the resultant vector with sorted results from both vectors
    vector<int> result;
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size())
    {
        // If the left value is smaller than the right it goes next
        // into the resultant vector
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }

    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
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


/*===========================================================================*/
/*==========Sorting Algorithms===============================================*/
/*===========================================================================*/

void insertionSort(vector<int> &v) {
    int i, j, value;

    for(i = 1; i < v.size(); i++) {
        value = v[i];
        for(j = i - 1; j >= 0 && v[j] > value; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = value;
    }
}

vector<int> mergeSort(vector<int>& vec) {
    
    
    if(vec.size() == 1) { // Termination condition: List is completely sorted.
        return vec; // only contains a single element.
    }

    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    // Perform a merge sort on the two smaller vectors
    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

void selectionSort(vector<int> &v) {
    int iPos;
    int iMin;
    for (iPos = 0; iPos < v.size(); iPos ++) {
        iMin = iPos;
        for (int i = iPos + 1; i < v.size(); i++) {
            if (v[i] < v[iMin])
                iMin = i;
        }
        if (iMin != iPos)
            swap(v[iPos], v[iMin]);
    }
}

void quickSort(vector<int>&v, int start, int stop) {
    if (stop > start) {
        int pivot = partition(v, start, stop); //for a better partitionning
        quickSort(v, start, pivot -1);
        quickSort(v, pivot + 1, stop);
    }
}

void bubbleSort(vector<int>&v) {

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < i; j++) {
            if (v[i] < v[j] ) {
                swap(v[i], v[j]);

            }
        }
    }
}


//////////////////////////////////////////////////////////////////
/***                 MAIN PROGRAM                             ***/
//////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

    srand(time(NULL));
    int DATA_SIZE = atoi(argv[1]);

    vector<int> v;
    int random_data;

	//fillVectorRandomly(v, DATA_SIZE);
	fillVectorSorted(v, DATA_SIZE);
	//fillVectorSemiRandomly(v, DATA_SIZE);
	printVector(v);

    cout <<"********Sorting with QuickSort  Algorithm********"<<endl;
    Timer timer;
    timer.begin();

    quickSort(v, 0, v.size() - 1);

    double time = timer.end();
    printf("ELAPSED TIME for sorting = %.6f seconds...", time);

    cout <<"********Sorting with Selection sort Algorithm********"<<endl;
    timer.begin();

    selectionSort(v);

    time = timer.end();
    printf("ELAPSED TIME for sorting = %.6f seconds...", time);

    cout <<"********Sorting with Insertion sort Algorithm********"<<endl;
    timer.begin();

    insertionSort(v);

    time = timer.end();
    printf("ELAPSED TIME for sorting = %.6f seconds...", time);

    cout <<"********Sorting with Merge sort Algorithm********"<<endl;
    timer.begin();

    vector<int> w = mergeSort(v);

    time = timer.end();
    printf("ELAPSED TIME for sorting = %.6f seconds...", time);

    cout <<"********Sorting with Bubble Sort Algorithm********"<<endl;
    timer.begin();

    bubbleSort(v);

    time = timer.end();
    printf("ELAPSED TIME for sorting = %.6f seconds...", time);

    cout <<"\n\n"<<endl;
    return 0;
}

