/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 7 mars 2011, 13:42
 * http://www.cpp-home.com/archives/67.htm
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
void readFile(ifstream &file) {
    
    char ch;
    while(!file.eof()) {
        file.get(ch);
        cout << ch;
    }   
}
/**************************************************************************/
/*                 MAIN PROGRAM                                           */
/**************************************************************************/
int main(int argc, char** argv) {
   
    fstream File("cpp-home.txt", ios::in | ios::out);  
    if(!File || File.fail()) { // you can use after File.is_open()
        cout << "File error ! Aborting ..\n";
        exit(1);
    }
//Status file check  using flags
    if(File.rdstate() == ios::eofbit)
        cout <<"End of File ! \n"<<endl;
    if(File.rdstate() == ios::badbit)
        cout <<"Fatal I/O error !\n"<<endl;
    if(File.rdstate() == ios::failbit)
        cout <<"Non-Fatal I/O error! \n"<<endl;
    if(File.rdstate() == ios::goodbit)
        cout <<"No errors, continue :) "<<endl;

    
    File << "Hello wold, fstream !"; //put "Hi!" in the file
    static char str[10]; //when using static, the array is automatically
    //initialized, and very cell NULLed
    File.seekg(ios::beg); //get back to the beginning of the file
    //this function is explained a bit later
    File >> str;
    cout << str << endl;
    File.close();

    //Overloading getline
    File.get(str, 10, 'o');
    cout <<str<<endl;
    File.close();

    ifstream OutFile("cpp-home.txt");
    char ch;
    char line[100];
    while (!OutFile.eof()) {
        OutFile.getline(line, 100); //printing lines instead of characters
        //OutFile.get(ch);
        cout <<line<<endl;
        //cout <<ch<<endl;
    }
    //use of get  and  put
    fstream ioFile1("test_file.txt", ios::in | ios::out | ios::binary);
    char chr;
    chr='o';
    ioFile1.put(chr);
    ioFile1.seekg(ios::beg);
    ioFile1.get(chr);
    cout <<chr<<endl;
    ioFile1.close();

    //use of read  write
    fstream ioFile2("test_file.txt", ios::in | ios::out | ios::binary);
    char array[20];
    strcpy(array, "IOoperations ");
    ioFile2.write(array, 5);
    ioFile2.seekg(ios::beg);
    static char read_array[20];
    ioFile2.read(read_array, 3);
    cout <<read_array<<endl;
    ioFile2.close();

    return 0;
}

