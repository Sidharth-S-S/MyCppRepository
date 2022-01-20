#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    /*
     All Prime Numbers
    Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
    Print the prime numbers in different lines.
    
    Constraints : 1 <= N <= 100
    Sample Input 1:  9
    Sample Output 1: 
    2
    3
    5
    7

    Sample Input 2:  20
    Sample Output 2:
    2
    3
    5
    7
    11
    13
    17
    19
    */
   int n ; 
   cin >> n ; 

   for ( int i = 2 ; i <=n ; i++ ) {
       bool PrimeFlag = true ;
       for (int j = sqrt(i);j>1;j--) {
           if (i % j == 0){
               // Now number is not prime
               PrimeFlag = false ;
               break;
           }
       }
       if (PrimeFlag) {
           cout << i << endl ;
       }
   }
}