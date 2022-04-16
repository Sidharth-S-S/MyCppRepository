#include<iostream>
using namespace std;

void print(int n){
    //write your code here
    if (n == 0 ){
        return ;
    }
    print(n-1);
    cout << n << " " ;
}

int main(int argc, char **argv) {

/* Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space) , O/p x^n */
int n ;
cin >> n ;
print(n) ;
}