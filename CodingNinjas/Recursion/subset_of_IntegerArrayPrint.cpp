#include "MyHeaderFiles.h"
#include "iostream"

/*----------------------------------------------------------------
for the logic please refer to the subset_of_integer_array  original files
----------------------------------------------------------------*/

void printSubsetsOfArray(int input[], int size) {
	// create 1 2d output array and it must have 16 elements or more to hold with 1st element as size and rest all are what to print
    // it ultimately depends on the size of the input array and hence i have used a dynamic memory allocation
    int * Output = new int[size];
    // no elements are present  in the output array initially is 0 
    printSubsetsOfArray_helper(input, size, Output, 0);
    delete [] Output;
    
}

void printSubsetsOfArray_helper(int input[], int size, int * Output,int OutputSize) {
    // Base Case :: if the array size is 0 then print everything in the output array 
    if (size==0) {
        for (int i = 0; i < OutputSize; i++){
            std::cout << Output[i] << " ";
        }
        std::cout << std::endl;
        return ;
    }

    // in the output case to be printed there is 1 way to go forward ; if our current element is used or not used 
    /* ----------------------------------------------------------------
    * e.g.   3 5 6 => call if we want to include 3 or not ; if include then output = 3 or []  && input = 5 6 
    * now next choice is input = 5 6 => either include 5 or not  ; input = 6 ; output multiple options
    * not we can either include 6 or not  ; we include then print 6 as input size  is 0 else we do not include still input size is 0 and you need to print the output.    
    */

   // small calculation ++ recursive call 

   // if the input[0] not to be considered ==> the size of the output is same and no need to modify output 
   printSubsetsOfArray_helper (input+1, size-1 ,Output,OutputSize) ;

   // now assume the 1st element to be considered => increase the output size by 1 ; copy all the contents and then add the newer element to the output.
   // create another array so that the newarray will be independent of the current output when there is a need to revisit the old output array.
   int NewArray[16];
   // copy all the elements now along with addition of 1st element of the input array 
   // 1sst copy the elements of the output array and the last element add the current element from the input array .
   for (int i = 0 ; i <= OutputSize ; i++) {
       if (i == OutputSize ){
           NewArray[i] = input[0];
           continue;
       }
       NewArray[i] = Output[i] ;
   }
   
   printSubsetsOfArray_helper (input+1, size-1, NewArray,OutputSize+1) ;
}

/*----------------------------------------------------------------
#include "iostream"
#include "cstring"
using namespace std;

#include "Recursion/MyHeaderFiles.h"


int main() {
  int input[20],length;
  cin >> length;
  for(int i=0; i < length; i++) {
    cin >> input[i];
  }
  
  printSubsetsOfArray(input, length);

}
----------------------------------------------------------------*/