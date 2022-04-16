#include <iostream>
using namespace std;

int LastIndex(int input[],int size,int x){
    //Base Case: input
    if (size == 0) return -1;

    // We need to find the last occurance of the element 

    // Small Calculation once done has no meaning as we have to recalculate so we will do the recursion 1st
    int PrevIdx = LastIndex(input+1 , size-1,x) ;

    // Now check if the PrevIdx is -1 then compare with the current element
    if (PrevIdx == -1) {
        if ( input[0] == x ) return 0 ;
        else return -1 ;
    } else {
        return PrevIdx+1; // as the recursion array starts from 1 not from 0 idx .
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
    cout << LastIndex(pa , n , x) << endl;

    // Always Free the dynamic memory once allocated
    delete[] pa ;

    return 0;
}