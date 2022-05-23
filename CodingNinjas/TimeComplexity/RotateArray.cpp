#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    /*Method 1 :: d position  to be shifted then 1 position shift then repeat the process again and again till d move is reached
        Method 2 :: Create another array temp with d elements , then shift the elements from the dth element to the 0th element  with  ith element == d+i th element
        Method 3 :: Reverse the entire array then  , n-d elements of the array gets reversed and then the later elements of the array will be reversed
    */

   int *TempArr = new int[d];

   for (int i = 0; i < d; i++) {
       TempArr[i] = input[i] ; // copy the d elements from 1st
   }

   for (int i = d; i < n; i++) {
       input[i-d] = input[i] ; 
   }

   for (int i = n-d; i < n ; i++) {
       input[i] = TempArr[i-n+d] ;
   }

   delete []TempArr;

}

int arrayRotateCheck(int *input, int size)
{
    /* 
    Input format : 
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
    First line of each test case or query contains an integer 'N' representing the size of the array/list.
    Second line contains 'N' single space separated integers representing the elements in the array/list.

    Output Format :
    For each test case, print the value of 'K' or the index from which which the array/list has been rotated.
    Output for every test case will be printed in a separate line.

    Sample Input 2:
    2
    5
    3 6 8 9 10
    4
    10 20 30 1

    Sample Output 2:
    0
    3
    */
   int idx = 0 ; 
   for (int i = 1; i < size; i++) {
       if (input[i] < input[i-1]){
           idx = i ;
           break ;
       }
   }
   return idx ; 
}

int main() {
    int t ; 
    cin >> t; // no of test cases

    while (t--) {

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
    }
}