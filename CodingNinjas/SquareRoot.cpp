#include <iostream>

using namespace std; 

int main() {
    /*
     
Given a number N, find its square root. You need to find and print only the integral part of square root of N.
For eg. if number given is 18, answer is 4.
Constraints :   0 <= N <= 10^8

Sample Input 1 : 10
Sample Output 1 : 3

Sample Input 2 : 4
Sample Output 2 : 2
    */
   long long int n ;
   cin >> n ;

   if (n > 3) {
       for (long long int i = n/2 ; i > 1 ; i--) {
           long long int Product = i * i ;
           if (Product <= n){
               cout << i ;
               break ;
           }
       }
   } else if (n>0){
       cout << 1 ;
    } else if (n==0){
        cout << 0;
    }
}