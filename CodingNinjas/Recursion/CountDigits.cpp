#include<iostream>
using namespace std;

int count(int n){
    // Base Case When the num is less than 10 return 1 ;; else when the num is 0 then return 0;
    if (n < 10) return 1;
    
    //Assume it is true for all iteration till n-1 iteration is reached
    int sum = 0;
    sum = 1 + count(n/10) ;
    return sum ;
}

int main(int argc, char **argv) {
/* Write a program to find x to the power n (i.e. x^n). Take x and n from the user. 
You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space) , O/p x^n */
int n ;
cin >> n ;
cout << count(n) ;

}