#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;


struct Stats {
    int min;
    int max;
    double average;
};


Stats  calculateStatistics(string filename) {

    Stats  stats;
    
    stats.min = 101; 
    stats.max = -1;
    int total = 0;
    int count = 0;
    
    //Open a new filestream and make sure it works
    ifstream in;
    in.open(filename.c_str());
    if(in.fail()) cout <<"Could not read ' "<< filename << "'"<<endl;
    
    //while (!file.eof()) {
    while (true) {
        int num;
        in >> num;
        //Check that we read successfully
        if(in.fail()) break;

        if(stats.min > num) stats.min = num;
        if(stats.max < num) stats.max = num;
        count ++;
        total += num;

    
        }

        //Watch out for integer devision 
        stats.average = double(total) / count;

        in.close();

return stats;
}

void printStatistics(Stats stats) {
    cout <<"min = "<<stats.min<<endl;
    cout <<"max = "<<stats.max<<endl;
    cout <<"Average = "<<stats.average<<endl;

}

/**********************************************/
/* print statistics about file in the input   */
/**********************************************/

int main () {

Stats stats = calculateStatistics("score.txt");

printStatistics(stats);

return 0;
}
