#include <iostream>
using namespace std;

int main()
{
    // Enter 2 Number to calculate the GCD of 2 numbers
   int a = 0 , b = 0 , diff = 0 , small = 0,large = 0; 
   cout << "Enter Number to calculate the GCD of 2 numbers" << endl;
   cin >> a >> b ;

   if (a > b) {
       small = b ;
       large = a ;
   } else {
        small = a ;
        large = b ;
   }
   diff = large - small ;
   while (diff >= 0)
    {
        if (diff  > 0) {
            if ((a % diff == 0) && (b % diff == 0)) {
                cout << "GCD of 2 numbers are : " << diff << endl;
                break;
            } else {
                diff -=  small ;
            }
        } else if (diff == 0) {
        cout << "GCD of 2 numbers are : " << a << endl;
        } 
    }
    if (diff <= 0) {
        cout << "GCD of 2 numbers are : " << 1 << endl;
        }
        cout << "Diff Value is : " << diff << endl;
    }