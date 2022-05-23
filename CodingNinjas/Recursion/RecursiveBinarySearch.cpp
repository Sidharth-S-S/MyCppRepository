// forward declaration of this function
#include "MyHeaderFiles.h"
// input - input array
// size - length of input array
// element - value to be searched

int binarySearch(int input[], int size, int element) {
    // base case
    if (size == 0) return -1; //

    // recursive search algorithm for binary search
    // mid = ( start + size - 1 ) / 2  search element at position mid is == element or not , if yes then the start and end element will be different

    return binarySearch_helper(input, 0, size-1,element) ;
}

int binarySearch_helper(int input[],int start_idx,int end_idx,int element){

    // base case
    if (start_idx > end_idx){
        return -1 ;
    }

    // small calculation
    int mid = (start_idx + end_idx) / 2 ;

    if (element == input[mid]) {
        return mid ;
    } else if (element > input[mid]) {
        // the element is from the mid to end side
        binarySearch_helper(input, mid+1,end_idx,element) ;
    } else { 
        // the element is from the start to mid-1
        binarySearch_helper(input,start_idx , mid-1, element);
    }
}