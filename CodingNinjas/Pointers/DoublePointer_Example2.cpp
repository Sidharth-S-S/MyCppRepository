#include <iostream>
using namespace std;


void increment(int **p){
  (**p)++;
}

int main(){
 int num = 10;
 int *ptr = &num;
 increment(&ptr); // address of the pointer is passed as argument to increment
 cout << num << endl;
}