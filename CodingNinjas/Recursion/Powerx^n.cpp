#include<iostream>
using namespace std;

int power(int x , int n){
    // Base Case for power is x is multiplied n times . if n is 0 x^0 is 1 or else if x = 0 then it would be 0 
    if (n == 0) {
        // return (x != 0 ? 1 : 0); // power 0 but x is zero or not check
        // always return 1 
        return 1 ; 
    }
    // call the power function n-1 times multiplying x 
    int PrevPow = power(x,n-1);
    int Pow =  x * PrevPow; //
    return Pow ;
}


int main(int argc, char **argv) {

/* Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space) , O/p x^n */
int x , n ;
cin >> x >> n ;
cout << x << " to the power " << n << " is : " << power(x,n) << endl;

// sprintf('The Power of %d to the power %d is %d'),x,n,power(x,n)) ;
}