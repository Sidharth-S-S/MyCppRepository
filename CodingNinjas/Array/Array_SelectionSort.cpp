#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/*  Selection Sort 

Step 1 : Find the minimum index of the array by traversing all the elements . 
            Once min is found then swap the 1st element with the minimum element .
Step 2 : Now here from index 1 -> end index array find the minimum element again and now again swap the elements
Step 3 : Continue the Process when we are at the  idx = last idx - 1 (as the last would automatically be there )

Size of the array = n 
Min Find and Swap logic = n-1 times

*/

void selectionSort(int *Array , int Size){

    // We need size - 1  times to iterate this loop .
    for (int i = 0; i < Size-1 ; i++){
        int Min = Array[i] ,MinIdx = i; // MinIdx is the element where we would sort the array .

        // Find the minimum element in rest of the array .
        for (int j = i+1 ; j < Size ; j++){
            if ( Array[j] < Min ) {
                Min = Array[j] ;
                MinIdx = j ;
            }
        }
        // Swap the elements at the MinIdx position with the i th Position . 
        int temp = Array[i] ; 
        Array[i] = Min;
        Array[MinIdx] = temp;
    }
}


int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray1[100000];
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N  ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }
        selectionSort(myArray1, N) ;
        
        //directly print the original array as the changes happened at the memory directly .
        for (int j = 0;j < N ; j++) {
            cout << myArray1[j] << " " ;
        }
    }
}
