#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/* 
Array Intersection
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.
The intersection elements printed would be in the order they appear in the first array/list(ARR1)


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements of the first the array/list.
Third line contains an integer 'M' representing the size of the second array/list.
Fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
Time Limit: 1 sec 

Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10

Sample Output 1 :
2 4 3
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
2 1 2

Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. 
Similarly, the second '2' of the first array matches with the second '2' if the second array.
*/

/*
Important point for the logic is we have to start comparing the elements from A1 with A2 . The loop comparison once elem is found can be stopped for the next element .   
Now if the value matches to avoid next  match   e.g.    2 2   vs  2    =>  replace 2nd array A2's  2 with  Integer_min so that 2nd array would be then modified but the next comparison wont yield the same result.
To avoid the change in the input array , create a temp array and then perform operation inside the function for better clarity.
*/


void Arrayintersection(int *input1, int *input2, int size1, int size2)
{
    int temp[100000] ; 
    for (int j = 0;j < size2 ; j++){
             temp[j] = input2[j] ;
        }
    
    for (int i = 0; i < size1 ; i++) {
        for (int j = 0; j < size2 ; j++) {
            if (input1[i] == temp[j]){
                cout << input1[i] << " ";
                temp[j] = INT_MIN ; // assigning max values so that next iteration onwards it would not be same.
                break;
            }
        }
    }
    cout << endl ;
}

int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray1[100000],myArray2[100000] ;
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N,M ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }
        cin >> M ;
        for (int j = 0;j < M ; j++){
            cin >> myArray2[j] ;
        }
        Arrayintersection(myArray1,myArray2, N,M) ;
        //directly print the original array as the changes happened at the memory directly .
        /*for (int j = 0;j < N ; j++) {
            cout << myArray[j] << " " ;
        } */
    }
}
