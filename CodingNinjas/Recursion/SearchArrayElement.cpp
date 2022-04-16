#include <iostream>
using namespace std;

/*
This function checks for a number in an array , if found returns true else returns false.
*/
bool checkNumber(int input[], int size, int x) {
  
  // base case check if the number is not at all present then size -1 will lead to 0 and i can return false directly
  if (size == 0) {
      return false ;
  }

  // check if the current element has the element else call the recursion
  if ( input[0] == x ) {
      return true ;
  } else {
      return checkNumber(input+1, size-1,x) ;
  }
}

int main(int argc, char **argv) {
    int n , x ;
    cout << "Enter the number of elements of the array . " << endl;
    cin >> n ;
    
    int * pa = new int[n];
    for (int i = 0; i < n; i++){
        cin >> *(pa+i) ; // better way is to use pa[i]
    }

    cin >> x ;
    
    // call the recursive function to find if the array is sorted or not
    cout << boolalpha << checkNumber(pa , n , x) << endl;

    // Always Free the dynamic memory once allocated
    delete[] pa ;

    return 0;
}