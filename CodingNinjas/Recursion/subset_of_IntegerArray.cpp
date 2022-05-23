/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

#include "MyHeaderFiles.h"

/****************************************************************
 * Assume the problem has 2 parts 1 part is handled by recursion and the output is already printed.
 * e.g. Elements are  let  6,7,8 => Recursion is handling 7,8 and the output is  0 [] , 1 7 , 1 8 , 2 7 8
 * now during the small calculation we need to handle 6 , so create a copy of all the 4 output .
 * in the index add +1 and in the array element add 6 at the next array idx . 
 * e.g. 0 [] now 0+1 and at the 1st idx add 6 => 1 6 ;;;; similarly
 * 1 7 => idx 1 has 7 now  at the 0th idx add +1 and at 2nd idx add 6 => 2 7 6 ;; so on
 ****************************************************************/

int subset(int input[], int n, int output[][20]) {
    // Base Case
    if (n==0){
        output[0][0] = 0;
        return 1;
    }

    //recursion call , assume it will handle and give the no of subset
    int PrevSubsetCount = subset(input+1,n-1,output) ;

    // small calculation
    for (int i = 0; i<PrevSubsetCount ; i++){

        // last half of the output array will be modified
        int newcolumn = output[i][0] + 1 ;
        for (int j = 0; j <= newcolumn ;j++){

            // for the 1st column just do not copy alone ; increment it by 1 and copy
            if (j==0){
                output[PrevSubsetCount + i][j] = newcolumn;
            } else if (j==1){
                // now for the column 1 the new element input[0] will be copied , other contents will be copied afterwards
                output[i+PrevSubsetCount][j] = input[0] ;
            } else {            
                output[PrevSubsetCount +  i][j] = output[i][j-1] ;  // verified by dry run ; e.g.  for element 76 assume the output was 1 6 => now it would be 2 7 6 ; 1+1 ; input[0] ; output[1]
            }
        }
    }
    
    return 2*PrevSubsetCount ;
}
