#include <iostream>
#include "MyHeaderFiles.h"

void printSubsetSumToK(int input[], int size, int k) {
    /********
     * Given an array A and an integer K, print all subsets of A which sum to K.
     * Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
     * Note : The order of subsets are not important. Just print them in different lines.
     * Input format : 
     * Line 1 : Size of input array
     * Line 2 : Array elements separated by space
     * Line 3 : K 
     * Sample Input:
     * 
     * 9 
     * 5 12 3 17 1 18 15 3 17 
     * 6
     * 
     * Sample Output:
     * 3 3
     * 5 1
     * ***************/

    /* 
    how to print the array :: We have to initialize an Output Array with 1 element which only stores the size of the no of elements of the output array.
    now we have 2 options to consider in the array whether to consider the element at   input[start]  or not , based on that we have to increase the 0th element in the array
    Then add the new element at the end of the array 
    and then return from the operation
    when start == size  &&  sum == 0 ; print all the numbers from 1 to output[output[0]]
    */

   // initialize the output array
   int output[1] = {0} ;
   printSubsetSumToK_helper(input,size,k,0,output) ;

}

void printSubsetSumToK_helper(int input[],int length, int TargetSum, int Idx, int Output[]) {

    // base case
    if (Idx == length){
        if (TargetSum == 0){
            for (int i = 1 ; i <= Output[0]; i++){ /* The 1st output element is at 0th idx so printing from Idx = 1 */
                std::cout << Output[i] << " ";
            }
            std::cout << std:: endl ;
        }
            return ;
    }

    // recursion call for the inclusion and not inclusion of the input[Idx]
    // Not included in the output array 

    printSubsetSumToK_helper (input,length,TargetSum,Idx+1,Output) ;

    // Included in the output array now as a new array
    int newarray[Output[0]+1];
    //int *NewArray = new int[Output[0]] ;

    newarray[0] = Output[0] +1 ;
    int i ; // initialize i outside so that it will be used to add current element also
    for (i = 1 ; i <= Output[0] ; i++) {
        newarray[i] = Output[i] ;
    }
    newarray[i] = input[Idx] ;

    printSubsetSumToK_helper(input, length,TargetSum- input[Idx],Idx+1,newarray);

}


/*
// DRIVE MAIN FUNCTION
int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
*/