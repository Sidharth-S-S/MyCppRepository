#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    // There are 3 approach
    // O n^2 is the complexity if we search 1 by 1 each element of the array and find the duplicate
    // Another Approach is to sort the elements and then find the consecutive elements for the duplicate
    // last approach is that it will have   0->n-2 consecutive elements , so we need to take the array sum and then subtract it from n-2 element sum

    int ArrSum = 0;
    for (int i = 0; i < n; i++){
        ArrSum += arr[i] ;
    }

    return ArrSum - ((n-2) * (n-1) * 0.5 ) ;
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

        cout << findDuplicate(input, size) << endl;
    }

    return 0;
}