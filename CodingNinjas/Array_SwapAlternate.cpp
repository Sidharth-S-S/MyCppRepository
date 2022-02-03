#include <iostream>
#include <cmath>
#include <climits>
using namespace std;


// There is no need of the return type due to direct modification of the array at memory
void swapAlternate(int *arr, int size)
{
    for (int i = 0; i < size-1; i+=2) {
        // swap the elements of ith and jth elements
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp ;
    }
}

int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray[10000] ;
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray[j] ;
        }
        swapAlternate(myArray, N);
        //directly print the original array as the changes happened at the memory directly .
        for (int j = 0;j < N ; j++) {
            cout << myArray[j] << " " ;
        }
    }
}
