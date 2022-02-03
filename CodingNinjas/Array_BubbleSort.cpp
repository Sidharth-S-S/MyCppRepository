#include <iostream>
#include <cmath>
using namespace std;

void bubbleSort(int *Array,int Size){
    // Bubble Sort is opposite of the Selection Sort , here the maximum element of the Array would be placed 1st from the end. 
    // If the size of the array is n then the loop has to run  n-1 times (last would be automatically sorted)
    for(int i = 0; i < Size-1; i++){
        // compare every adjacent element of the array till the last element of the ith Iteration is sorted.
        // j -> j+1 compare till  j+1 => last element ( Size - i) 
        for (int j = 0; j < Size - 1 - i; j++){
            if (Array[j] > Array[j+1]){
                // Larger elements would be shifted towards the end of the array
                int temp = Array[j+1] ;
                Array[j+1] = Array[j] ;
                Array[j] = temp ;
            }
        }
    }
}

void printArray(int *Array,int Size){
    for (int i=0;i<Size;i++){
        cout << Array[i] << " ";
    }
    cout << endl;
}

int main(){
    int t = 1 ,myArray1[100000]={0} /* Initialize 1 Element as 0 so that others would be automatically initialized */;
    cin >> t ;  // Number of Tests to Execute

    for (int i = 1 ; i <= t ; i++) {
        int N  ;  // Size of the Array as input
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;  // enter the element 1 by 1 
        }

        bubbleSort(myArray1, N) ;
        
        //directly print the original array as the changes happened at the memory directly .
        printArray(myArray1, N) ;
    }
}