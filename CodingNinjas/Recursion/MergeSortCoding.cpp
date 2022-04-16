#include <iostream>
using namespace std;

void mergeSortedArrays(int *myArray, int Start , int End , int Mid){
    int FirstIdx = Start , SecIdx = Mid + 1 , ThirdIdx = Start , OutputArr[End+1] = {0};

    while (FirstIdx <= Mid && SecIdx <= End) {
        
        if (myArray[FirstIdx] <= myArray[SecIdx]){
            OutputArr[ThirdIdx] = myArray[FirstIdx] ;
            FirstIdx++;
        } else {
            OutputArr[ThirdIdx] = myArray[SecIdx] ;
            SecIdx++;
        }
        ThirdIdx ++ ;
    }

    // Now copy other elements to the mixed array 
    while ( ThirdIdx <= End ) {
        if ( FirstIdx == Mid+1 ) {
            OutputArr[ThirdIdx] = myArray[SecIdx] ;
            SecIdx++;
        } else {
            OutputArr[ThirdIdx] = myArray[FirstIdx] ;
            FirstIdx++;
        }
        ThirdIdx++ ;
    }

    // All the elements Copy Back to the 1st Array
    for ( int Idx = Start ; Idx <= End ; Idx++) {
        myArray[Idx]  =  OutputArr[Idx] ;
    }
}

void helper_MergeSort(int * myArr , int Start, int End){
    int Mid = (Start + End) / 2; // 0 -> 4 means , Array len = 5 , 0 + 4 / 2 => 2 ; 0 - 2 1 part other part 2+1 -> 4

    // Base Case will be when the array elements at the start and end match or  start > end then return . 
    if ( Start >= End ) return;

    // Recursion will sort 2 halves of the array 
    // To sort using Merge Sort we need to divide the array by 2 halves and assume the recursion is sorting them
    helper_MergeSort(myArr , Start , Mid ) ; // from Start to Mid index assume it is gonna sort and give 
    helper_MergeSort(myArr , Mid+1 , End ) ; // 2nd part is also sorted by the recursion .

    // Simple Calculation part where we have to merge 2 sorted arrays 
    mergeSortedArrays(myArr , Start , End , Mid) ;
}

void MergeSort(int *Arr , int size) {

    // Base Case for the Array is that if the array size is 1 or 0 then the array is already sorted
    if ((size == 1) || (size == 0 )) {
        return;
    }

       // now call a helper function that will take the array elements and the start and the end index with it . 
    helper_MergeSort(Arr, 0, size-1 ) ;

}

int main (int argc, char **argv) {
    int n ; 
    cin >> n ;
    int *myArray = new int[n];

    for (int i = 0; i < n ; i++) {
        cin >> *(myArray+i) ; 
    }

    MergeSort(myArray,n) ;

    for (int i = 0; i < n ; i++) {
        cout << *(myArray+i) << ' ';
    }

    // delete the memory
    delete [] myArray ;
}