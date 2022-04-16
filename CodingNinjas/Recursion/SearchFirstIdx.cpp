#include <iostream>
using namespace std;

int FirstIndex(int input[],int size,int x){
    //Base Case: input
    if (size == 0) return -1;

    // Recursion 
    // Small Calculation for 1 case 

    // Check if the idx is
    if (input[0] == x) return 0; 
    int PrevOp = FirstIndex(input+1,size-1,x) ;
    
    if (PrevOp != -1) {
        return PrevOp+1 ; // As the 1st element is already considered so //Always perform DryRun
    } else {
        return -1;
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
    cout << FirstIndex(pa , n , x) << endl;

    // Always Free the dynamic memory once allocated
    delete[] pa ;

    return 0;
}