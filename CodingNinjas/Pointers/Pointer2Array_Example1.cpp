#include <iostream>
using namespace std;
int main ()
{
  int numbers[5];
  int * p;
  p = numbers; // 1st element of array 
  *p = 10;
  p = &numbers[2];  // numbers[2] = *(numbers + 2) // it is now 3rd element of array
  *p = 20;
  p--;  // 2nd element of array
  *p = 30;
  p = numbers + 3; // numbers + 3 => 4th element of array
  *p = 40;
  p = numbers; // 0th idx , 1st element of array
  *(p+4) = 50; // 4th idx => 5th element of array
  for (int n=0; n<5; n++) {
     cout << numbers[n] << ",";
  }
  return 0;
}