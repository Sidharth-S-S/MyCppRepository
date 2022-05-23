/***
You need to save all the subsets in the given 2D output array. 
And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

/****************************************************************
 * Quite complex approach is here for this logic ; however the aim is that the sum of the numbers will be k ;
 * let the array we will take is 1 ,3 ,4, 2 k = 5 => there is a chance to include 1 or not based on that let 
 * 1 is not included => 3 , 4 , 2 and k = 5  will give output ass 3 + 2 
 * if 1 is included then k = 5-1 = 4 ; from 3,4,2 we can consider either to include 3 ; if include 3 => Output size = 0 but elements are 2 , 1 , 3 and k= 4-3 = 1; 
 * now we can not include 2 as  k < 2 ; hence if we do not include 2 , array size becomes 0 and k != 0 so The Output array is wrong and just return 0 from this loop
 * 
 * once 3 include is wrong next we have to include the next index i.e. 4 ; Output is 1,4 k = 4-4=0; Now return 1 and update the array 1st Col with proper size.
 *************/

# include "iostream"
# include "cstring"
using namespace std;

int subsetSumToK_helper(int input[], int size, int output[][50], int k, int startIdx){

    // base case
    if ( startIdx == size){
        if (k == 0 )  {
            output[0][0] = 0 ; // clear the output array 
            return 1; // last element is hit and the sum is 0 ;
        }
        else return 0 ;
    }

    // conditional recursion
    int output1[1000][50],output2[1000][50] ;
    int IncludeSize = 0 , NotIncludeSize = 0;

    
    //start the operation with startIdx+1 and 
    IncludeSize     = subsetSumToK_helper(input, size, output2, k-input[startIdx], startIdx+1) ;
    NotIncludeSize  = subsetSumToK_helper(input, size, output1, k, startIdx+1) ; 

    // now copy the output small calculation output to the main arrays
    for (int i = 0; i < NotIncludeSize; i++){
        for (int j = 0; j < output1[i][0];j++){
            output[i][j] = output1[i][j] ;
        }
    }

    // now we have to add the 1st element to the Include part & update the size of the element by 1 
    for (int i = 0 ; i < IncludeSize ; i++) {
        for (int j = output2[i][0] ; j >= 0 ; j--) { // 1st copy from back so that the elements are not lost
            if (j==0){
                output[NotIncludeSize + i][j] = output2[i][j] + 1 ; //size +1 because 1 element will be added now at input[start]
            } else if (j==1){
                output[NotIncludeSize + i][j] = input[startIdx] ; // element 1 has to be the current element of interest
            } else {
                output [NotIncludeSize + i][j] = output2[i][j-1] ; // -1 because the elements will be stored like 
                // e.g. : 2 1 4 and input[si] = 3 => o/p => 3 3 1 4 ; j=1 has input[si] ; j = 0 will be increased by 1 ; 
                // element 1 is copied to 2 and element 2 is copied to 3 
            }
        }
    }

    return NotIncludeSize + IncludeSize ;

}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // There is a need of the index to consider for the operation along with the available elements

    return subsetSumToK_helper(input,n,output,k,0) ;
    
}