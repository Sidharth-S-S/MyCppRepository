#include <iostream>
#include <cmath>
#include <limits>       // std::numeric_limits
using namespace std; 

/*
Given a number N, figure out if it is a member of fibonacci series or not. 
Return true if the number is member of fibonacci series else false.

Fibonacci Series is defined by the recurrence
    F(n) = F(n-1) + F(n-2)
    where F(0) = 0 and F(1) = 1

Constraints :   0 <= n <= 10^4
Sample Input 1 : 5
Sample Output 1 : true
Sample Input 2 : 14
Sample Output 2 : false    
*/
bool checkMember(int n){

    int first = 0,second = 1 , Fib_Num = 0;

    while ( Fib_Num < n){
        first = second;
        second = Fib_Num;
        Fib_Num = first + second ;
    }
    if (Fib_Num == n){
        return "true";
    } else {
        return "false";
    }
}


int main() {
    cout << "Enter the num" << endl ;
    int n;
    cin >> n;
    cout << checkMember(n) << endl;
    if (checkMember(n)) {
        cout << "true" ;
        } else {
            cout << "false" ;
        } 
}