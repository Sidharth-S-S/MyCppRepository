#include <iostream>
using namespace std;

int main()
{
    /* Initial

     Nth Fibonacci Number
    Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

        F(n) = F(n-1) + F(n-2), 
        Where, F(1) = F(2) = 1
        Sample Input 1: 6          
        Sample Output 1: 8
        Explanation of Sample Input 1: 
    Now the number is ‘6’ so we have to find the “6th” Fibonacci number So by using the property of the 
    Fibonacci series i.e   [ 1, 1, 2, 3, 5, 8] So the “6th” element is “8” hence we get the output.
    */
   int n = 0,Fibonacci_Num = 1,first_Num = 1,second_Num = 1;
   cin >> n;

   if (n > 2) {
       for (int i = 0; i < n-2 ; i++){
           Fibonacci_Num = first_Num + second_Num;
           first_Num = second_Num ;
           second_Num = Fibonacci_Num ;
       }
    }
    cout << Fibonacci_Num << endl;
}