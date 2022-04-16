#include <iostream>
using namespace std;


int main(){
int a = 10;
int *p = &a; // Adress of variable a is stored in p
int **q = &p; // address of variable p is stored in q
int b = 20;
*q = &b; // *q => value is q => i.e p = address of variable b
(*p)++; // value in address p ( variable b ) ++ 
cout << a << " " << b << endl;

//  Guess the Output
int a1 = 100;
int *p1 = &a1;
int **q1 = &p1;
int b1 = (**q1)++ + 4;
cout << a1 << " " << b1 << endl;

}