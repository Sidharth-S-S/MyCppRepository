#include "iostream"
using namespace std;

int partition(int *myArray , int Start , int End ) {
    // send the count to tha main function 
    int PivotCount = 0;

    for (int idx = Start + 1 ; idx <= End ; idx++) {
        if ( myArray[Start] >= myArray[idx] ) {
            PivotCount ++; //
        }
    }

    PivotCount += Start ; // As the index would be Start + PivotCount

    // Now swap the Pivot element with the Pivot Count Element
    int PivotValue = myArray[Start] ; 
    myArray[Start]  = myArray[PivotCount] ;
    myArray[PivotCount] = PivotValue ;


    // Now Sort the Array at the Pivot Point 
    // so that all the elements less than or equal to Pivot is towards left 
    // All the elements greater than Pivot are towards right

    int i = Start , j = End ; // i points to the 1st element and j points to the last element and they would ++ / --   based on conditions

    while ((i < j ) && (i < PivotCount) && (j >PivotCount )) {
        // condition is like 
        // case 1 : if the Array[i] <= PivotValue , i++ & continue 
        // case 2 : if the Array[i] > PivotValue , then check for Array[j] 
        // case 2a :if the Array[j] > PivotValue , then j-- and continue 
        // case 2b :if the Array[j] <= PivotValue , then swap the elements
        if ( myArray[i] <= PivotValue ) {
            i++ ;
            continue ;
        } else {
            if ( myArray[j] > PivotValue ) {
                j-- ;
                continue ;
            } else {
                // swap the elements
                int tempVel = myArray[i] ;
                myArray[i] = myArray[j] ;
                myArray[j] = tempVel ;
            }
        }
    }
    return PivotCount;    
}


void quickSort_helper(int *myArray , int start , int end) {
    // Base Case  if by the way of handling the start and end idx they overlap then return 
    if (start >= end) return;

    // Quick Sorting Algorithm says that we need to create a partition around 1 Pivot point 
    int Count = partition(myArray , start , end ) ; // it will put the pivot point in the proper position and arrange the elements 

    // call the quick sort function at the count position .
    quickSort_helper(myArray , start , Count-1) ;
    quickSort_helper(myArray , Count+1, end) ;
}

void quickSort(int input[], int size) {
    // Base Case also is that when the  size is 0 / 1 then return  
    if ((size == 1) || (size == 0 )) {
        return;
    }

    // call the helper function now with the start and the end index totally as the parameters
    quickSort_helper(input, 0 , size - 1 ) ;
}


int main(int argc, char **argv) {
    int n ; 
    cin >> n ;
    int *myArray = new int[n];

    for (int i = 0; i < n ; i++) {
        cin >> *(myArray+i) ; 
    }

    quickSort(myArray,n) ;

    for (int i = 0; i < n ; i++) {
        cout << *(myArray+i) << ' ';
    }

    // delete the memory
    delete [] myArray ;

}