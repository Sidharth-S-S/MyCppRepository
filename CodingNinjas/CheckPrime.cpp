#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n ,divisor = 2;
    bool PrimeFlag = true ; // Initialize a Prime Flag so that it would be set to true if the prime is true else it will be false
    cout << "Enter a number to check PRIME ." << endl;
    cin >> n ;

    // Prime number will not be divisible by any other number except itself and 1 . check from 2 .. root N
    int p = sqrt(n) ;

    while (divisor <= p ) {
        if (n % divisor == 0 ) {
            cout << "The number provided " << n << " is not a Prime Number" << endl ;
            PrimeFlag = false ;
        }
        divisor ++ ;
    }
    if (PrimeFlag) cout << "The number provided " << n << " is a Prime Number" << endl ;
}