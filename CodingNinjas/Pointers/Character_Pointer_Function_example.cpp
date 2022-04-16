#include<iostream>
using namespace std;
void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

int main()
{
   char *x = "geeksquiz";
   char *y = "geeksforgeeks";
   char *t;
   swap(x, y);
   cout<<x << " "<<y;
   t = x;
   x = y;
   y = t; 
   cout<<" "<<x<< " "<<y;
   return 0;

   // analyse the answer and write why it was
   // 1st calling the function the change is happening in the Function scope with respect to the copy created for the t , x , y variable
   // 2nd time the swap is occuring in the main function scope and hence the result will swap the x and y variables .
}