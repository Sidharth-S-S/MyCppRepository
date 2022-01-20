#include <iostream>
using namespace std; 
int main() {
    /*
    Given a binary number as an integer N, convert it into decimal and print.

    Input format :  An integer N in the Binary Format
    Output format : Corresponding Decimal number (as integer)
    
    Constraints : 0 <= N <= 10^9
    Sample Input 1 :  1100
    Sample Output 1 : 12

    Sample Input 2 :   111
    Sample Output 2 :   7
    */

   int binary, decimal = 0,temp,IdxFlag=1 ;
   cin >> binary ;
   temp = binary ;

   while (temp > 0) {
       decimal = decimal + (temp % 10)*IdxFlag ;
       IdxFlag = IdxFlag * 2 ;
       temp = temp / 10 ;
   }
   cout << decimal << endl;
}