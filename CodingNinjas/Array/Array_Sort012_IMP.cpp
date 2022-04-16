#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void sort012(int *arr, int n)
{
    //Write your code here
    // Sort 0 , 1 , => Count number of 0 , 1 , 2 and then add them 1 by 1 
    // Method 2 : Temporary Array , start placing 0 from start and place all 2 from end in the array .
    // NextZeroIdx = 0 -> ++ 
    // NextTwoIdx = 2 -> -- 

    // Method 3 is actually keeping a track of all the Zeros from NextZeroIdx starting 0 till Next2Idx = size-1 
    // If the Size is down for the current element at ith till NextTwoIdx then stop
    // Incase you find a 0 at ith then swap it with the NextZero Directly 
    // Incase you find a 2 at ith then swap it with NextTwoIdx Directly
    // NextZeroIdx ++ , NextTwoIdx ++ 
    int nextZeroIdx = 0 , nextTwoIdx = n-1 ;
    // discard the cases where the last index is 2 
    
    for (int i = 0; i <= nextTwoIdx ; i++){

        // Adjust the Array Element for swapping 
            while (arr[nextTwoIdx] == 2){ 
                nextTwoIdx -- ; 
            }

        // CHeck if 2 is the current Array element
        if ( arr[i] == 2){

            // Swap the ith element with NextTwoIdx
            int temp = arr[nextTwoIdx] ;
            arr[nextTwoIdx] = arr[i] ; 
            arr[i] = temp ;
            // Make the idx ready for next cycle
            nextTwoIdx -- ;
        }
        if (arr[i] == 0) {
            
            // Swap only if the index value is not zero else no need 
            if (arr[nextZeroIdx] != 0) {
            int temp = arr[nextZeroIdx] ;
            arr[nextZeroIdx] = arr[i] ; 
            arr[i] = temp ;
            }
            nextZeroIdx ++ ;
        }
    }
}

void printArray(int *Array , int Size){
    for (int i = 0 ; i < Size;i++){
        cout << Array[i] << " " ;
    }
    cout << endl;
}

int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray1[100000];
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }       
        sort012(myArray1, N) ;
        printArray(myArray1,N);
    }
}