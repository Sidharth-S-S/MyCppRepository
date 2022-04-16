#include <iostream>
using namespace std;
void Q(int z)
{
  z += z;
  cout<<z << " ";
}

void P(int *y) 
{
  int x = *y + 2;  // *y means the value of address y which is address of x ; x value = 5 + 2 = 7 
  Q(x); // x is passed as 7 and it prints 14
  *y = x - 1; // *y is the value at the address of x (of the main) and any change here will reflect in main (important) 
  cout<<x << " ";
}

int main()
{
  int x = 5;
  P(&x); // Address of x is passed , so any change in the address will not impact , but   any change in the value will affect
  cout<<x;
  return 0;
}