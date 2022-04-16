#include <iostream>
using namespace std;

bool isSorted(int * p , int size) {
    // To use Recursion find the base case 
    // When the Array Size is equal to 0 or 1 then we can just return true 
    if ((size == 0) || (size == 1)) return true;

    // Now you have to call the array recursively with reduced array size 
    bool PrevResult = isSorted(p+1,size-1);

    // Do operation for the current operation 
    // if the Prev Result is already false then return false else compare the 0th and 1st elements
    
    if (PrevResult) {
        if (p[0] > p[1]) return false;
        else return true;
    } else {
        return PrevResult;
    }
}

bool isSorted2(int * p , int size) {
    // To use Recursion find the base case 
    // When the Array Size is equal to 0 or 1 then we can just return true 
    if ((size == 0) || (size == 1)) return true;

    if (p[0] > p[1]) return false;

    // Now you have to call the array recursively with reduced array size 
    bool PrevResult = isSorted2(p+1,size-1);
    return PrevResult;

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
    cout << boolalpha << isSorted2(pa , n) << endl;

    // Always Free the dynamic memory once allocated
    delete[] pa ;

    return 0;
}