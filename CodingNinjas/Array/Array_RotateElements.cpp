#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void rotate(int *input, int d, int n)
{
    // Write a function that rotates the given array/list by D elements(towards the left).
    // First line of each test case or query contains an integer 'N' representing the size of the array/list.
    // Third line contains the value of 'D' by which the array/list needs to be rotated.
    int TempArray[1000000] ;

    for(int i = 0; i < d ; i++) {
        TempArray[i] = input[i] ;
    }
    
    for(int i = 0; i < n-d ; i++){
        input[i] = input[i+d] ;
    }
    
    for(int i = n-d ; i < n ; i++){
        input[i] = TempArray[i-n+d] ;
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
    int t = 1 ,myArray1[1000000];
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N ,D ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }
        cin >> D ;
        /*
        cin >> M ;
        for (int j = 0;j < M ; j++){
            cin >> myArray2[j] ;
        }
        */ 
        rotate(myArray1, D , N) ;
        printArray(myArray1,N);
    }
}