#include <iostream>
using namespace std;

int findUnique(int *arr, int n) {
    /* You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
    Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
    You need to find and return that number which is unique in the array/list. 

    Method 1 : keep on comparing the element like 1 element with all , next with all ..... when 1 match not fond that i the an wer. => O(n^2)
    Method 2 : sort the array 1st and then we can compare them 1 by 1 traversing through the array/list . O(nlogn) + O(n) => O(nlogn)  
    Method 3 : Xor technique ; take Xor of the elements of the array ; the result is the unique element
    */
   int result = 0;
   for (int i = 0; i <n ; i++) {
       result ^= arr[i] ;
   }
   return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}