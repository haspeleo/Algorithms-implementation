/*
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 31 mars 2011, 16:55
 */

#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

/*
 * Stack Manipulation
 */
int main(int argc, char** argv) {

//	Stack<int> stack;
//
//	if(stack.isEmpty())
//	    cout <<"Empty Stack!"<<endl;
//	else
//	    cout <<"You can push elements "<<endl;
//
////	stack.push(1); // ush(1); //push<int>(1);


    return 0;
}






//Stack implementation as a class.

//#include<iostream>
//#include<cstdlib>
//
////#include<process>
//
//using namespace std;
//
//#define SIZE 20
//
//class stack {
//    int a[SIZE];
//    int tos; // Top of Stack
//public:
//    stack();
//    void push(int);
//    int pop();
//    int isempty();
//    int isfull();
//};
//
//stack::stack() {
//    tos = 0; //Initialize Top of Stack
//}
//
//int stack::isempty() {
//    return (tos == 0 ? 1 : 0);
//}
//
//int stack::isfull() {
//    return (tos == SIZE ? 1 : 0);
//}
//
//void stack::push(int i) {
//    if (!isfull()) {
//        a[tos] = i;
//        tos++;
//    } else {
//        cerr << "Stack overflow error !  Possible Data Loss !";
//    }
//}
//
//int stack::pop() {
//    if (!isempty()) {
//        return (a[--tos]);
//    } else {
//        cerr << "Stack is empty! What to pop...!";
//    }
//    return 0;
//}
//
//int main() {
//    stack s;
//    int ch = 1, num;
//    while (ch != 0) {
//        cout << "Stack Operations Mani Menu \n 1.Push \n 2.Pop \n 3.IsEmpty \n 4.IsFull \n 0.Exit"<<endl;
//
//                cin >> ch;
//        switch (ch) {
//            case 0:
//                exit(1); //Normal Termination of Program
//            case 1:
//                cout << "Enter the number to push";
//                cin >> num;
//                s.push(num);
//                break;
//            case 2:
//                cout << "Number popped from the stack is: " << s.pop() << endl;
//                break;
//            case 3:
//                (s.isempty()) ? (cout << "Stack is empty."):(cout<<"Stack is not empty.");
//                break;
//            case 4:
//                (s.isfull()) ? (cout << "Stack is full."):(cout<<"Stack is not full.");
//                break;
//            default:
//                cout << "Illegal Option. Please try again";
//                }
//    }//end of while
//    //getch();
//    return 0;
//}
