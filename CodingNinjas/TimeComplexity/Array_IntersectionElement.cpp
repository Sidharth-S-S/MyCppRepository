#include <iostream>
using namespace std;

//Pre Declaration:
void intersection( int * , int * ,int , int ) ;

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

void MergeSort(int * myArr , int Start, int End){
    int Mid = (Start + End) / 2; // 0 -> 4 means , Array len = 5 , 0 + 4 / 2 => 2 ; idx => 0 -> 2 , 1 part & other part =>  idx : 2+1 -> 4

    // Base Case will be when the array elements at the start and end match or  start > end then return . 
    if ( Start >= End ) return;

    // Recursion will sort 2 halves of the array 
    // To sort using Merge Sort we need to divide the array by 2 halves and assume the recursion is sorting them
    MergeSort(myArr , Start , Mid ) ; // from Start to Mid index assume it is gonna sort and give 
    MergeSort(myArr , Mid+1 , End ) ; // 2nd part is also sorted by the recursion .

    // Simple Calculation part where we have to merge 2 sorted arrays 
    mergeSortedArrays(myArr , Start , End , Mid) ;
}

void intersection( int *Arr1, int *Arr2,int size1 , int size2 ) {
    // here 1 approach is to find each element of the 1st array in the 2nd array and if the match is found then replace it with -inf  for the duplicate match
    // it will be working fine but time complexity is O m*n 
    // another approach is to sort 2 arrays and then keep on comparing 1 by 1 the elements and like merging 2 sorted array

    MergeSort (Arr1,0,size1-1) ; // now array 1 is sorted 

    MergeSort (Arr2,0,size2-1) ; // now array 2 is sorted also

    int i = 0 , j = 0 ; // 2 elements to traverse through the array elements

    while (i < size1 && j < size2) {
        // check for the array 1 
        // check foe the array 2 
        if (Arr1[i] == Arr2[j]) {
            cout << Arr1[i] << " " ;
            i++ ;
            j++;
        } else if (Arr1[i] < Arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
}

int main() {
    int t ; 
    cin >> t; // no of test cases

    while (t--) {
        int n,m ;
        cin >> n;
        int *Arr1 = new int[n];
        for (int i=0; i<n; i++) {
            cin >> Arr1[i];
        }

        cin >> m ;
        int *Arr2 = new int[m] ;

        for (int i=0; i<m; i++) {
            cin >> Arr2[i];
        }

        intersection(Arr1, Arr2, n, m);

        delete[] Arr1;
        delete[] Arr2;
    }
}