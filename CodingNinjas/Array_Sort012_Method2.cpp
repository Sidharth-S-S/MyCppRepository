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

    int nextZeroIdx = 0 , nextTwoIdx = n-1 ,tempArray[100000];
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == 0){
            tempArray[nextZeroIdx] = 0;
            nextZeroIdx++;
        } else if (arr[i] == 2){
            tempArray[nextTwoIdx] = 2 ;
            nextTwoIdx -- ;
        }
    }
    for (int i = nextZeroIdx ; i <= nextTwoIdx ; i++) {
        tempArray[i] = 1 ;
    }
    for (int i = 0 ; i < n ; i++) {
        arr[i] = tempArray[i];
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