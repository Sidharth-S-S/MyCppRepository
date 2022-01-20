#include <iostream>
using namespace std; 
int main() {
    /*
    Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
    
    Input format : Integer x
    Output format : Terms of series (separated by space)
    Constraints : 1 <= x <= 1,000

    Sample Input 1 :    10
    Sample Output 1 :   5 11 14 17 23 26 29 35 38 41

    Sample Input 2 :    4
    Sample Output 2 :   5 11 14 17
    */
   int n = 1;
   cin >> n ;
   
   for(int i = 1 , series_n = 1; i <= n ; series_n++){
        int Series_Number = 3*series_n + 2 ;
        if (Series_Number % 4 == 0) {
            continue ;
        }
        i++;
        cout << Series_Number << " ";
   }
}