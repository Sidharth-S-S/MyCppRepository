#include <iostream>
using namespace std;

int sum(int input[], int n) {
    // base case if the element size is 0 then return 0   else size 1 return the last element
    if (n == 1)  return input[0]; 

    // recursion till the end element and call the Array sum function with reducing size 
    return input[0] + sum( input+1, n-1 );
}

int main(int argc, char **argv) {
    int n ;
    cout << "Enter the number of elements of the array . " << endl;
    cin >> n ;
    
    int * pa = new int[n];
    for (int i = 0; i < n; i++){
        cin >> *(pa+i) ; // better way is to use pa[i]
    }

    // call the recursive function to find if the array is sorted or not
    cout << sum(pa , n) << endl;

    // Always Free the dynamic memory once allocated
    delete[] pa ;

    return 0;
}