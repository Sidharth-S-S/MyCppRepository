#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/* Triplet Sum
You have been given a random integer array/list(ARR) and a number X. Find and return the number of triplets in the array/list which sum to X.

Note : Given array/list can contain duplicate elements.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.
Third line contains an integer 'X'.

Output format :
For each test case, print the total number of triplets present in the array/list.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 50
0 <= N <= 10^2
0 <= X <= 10^9
Time Limit: 1 sec

Sample Input 1:
1
7
1 2 3 4 5 6 7 
12

Sample Output 1:
5

Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10

Sample Output 2:
0
5

Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.
For the second query, we have 5 triplets in total that sum up to 10. 
They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)

*/

int pairSum(int *input, int size, int x)
{
    int count = 0 ; 
	//Write your code here
    // size -2 as the last triplet would be at the index @size-3 , @size-2 & @size-1 .
    for (int i = 0; i < size-2; i++) {
        int first_num = input[i];
        for (int j = i + 1 ; j < size-1 ; j++){
            int second_num = input[j] ;
            for (int k = j+1 ; k < size; k++){
                if ((x - first_num - second_num) == input[k]){
                    count ++ ;
                }
            }
        }
    }
    return count ;
}

int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray1[100000];
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N,Sum;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }
        cin >> Sum ;
        /*
        cin >> M ;
        for (int j = 0;j < M ; j++){
            cin >> myArray2[j] ;
        }
        */
        cout << pairSum(myArray1, N,Sum) << endl;
        //directly print the original array as the changes happened at the memory directly .
        /*for (int j = 0;j < N ; j++) {
            cout << myArray[j] << " " ;
        } */
    }
}
