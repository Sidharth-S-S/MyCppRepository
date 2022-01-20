#include<iostream>
#include<cmath>
using namespace std;

int main() {
    /* 
    Given three values - 
    Start Fahrenheit Value (S), 
    End Fahrenheit value (E) 
    and Step Size (W), 
    you need to convert all Fahrenheit values from Start to End at the gap of W, into their corresponding Celsius values and print the table.
    0 <= S <= 80
    S <= E <=  900
    0 <= W <= 40 
    */

   int Start = 0, End = 0 , StepSize = 0 , Celsius = 0 , tempValue = 0;
   //cout << "Start:  End: Step Size: " << endl ;
   cin >> Start >> End >> StepSize ;
   tempValue = Start ;
   while (tempValue <= End){

       Celsius = (5* (tempValue - 32)) / 9 ;
       //cout << "Fahrenheit: " << tempValue << "\t Celsius: " << Celsius << endl ;
       cout << tempValue << "\t" << Celsius << endl ;
       tempValue += StepSize ;

   }

}