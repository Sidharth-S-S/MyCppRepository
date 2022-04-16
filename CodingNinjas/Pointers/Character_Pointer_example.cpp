#include <iostream>
using namespace std;
int main()
{
  char arr[20];
  int i;
  for(i = 0; i < 10; i++) {
    *(arr + i) = 65 + i; // A , B , C ....
  }
  *(arr + i) = '\0';  // only print 10elements from 20
  cout << arr;
  return 0;
}