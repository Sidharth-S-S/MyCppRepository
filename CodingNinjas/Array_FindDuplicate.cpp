#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/* You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the unique element present in the array.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
Time Limit: 1 sec

Sample Input 1:
1
7
2 3 1 6 3 6 2

Sample Output 1:
1
Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7

Sample Output 2:
4
10
*/
// There is no need of the return type due to direct modification of the array at memory

int duplicateNumber(int *arr, int size)
{
    //Write your code here
    int duplicateNumber = 0;
    for (int i = 0; i < size; i++){
        bool found = false;
        for (int j = size-1; j > i; j--){
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (found) {
            duplicateNumber = arr[i];
            break ;
        }
    }
    return duplicateNumber ;
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
        cout << " " << duplicateNumber(myArray, N) << endl;
        //directly print the original array as the changes happened at the memory directly .
        /*for (int j = 0;j < N ; j++) {
            cout << myArray[j] << " " ;
        } */
    }
}
