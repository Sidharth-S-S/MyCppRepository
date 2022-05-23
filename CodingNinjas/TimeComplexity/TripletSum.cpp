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

int pairSum(int *arr, int n, int num)
{
	// You have been given an integer array/list(ARR) and a number 'num'. 
    // Find and return the total number of pairs in the array/list which sum to 'num'
    // e.g. Array always check if sorting will improve the time complexity or not . 
    // pair sum is done in a way like  1ST element consider then reduce the target by the number ==> recursion example was there , when array end and target is 0 => print 
    // Method2 is sort the array and then try to find out 
    //MergeSort (arr ,0, n - 1) ; // now array is sorted
    int i = 0 , j = n-1 , PairCount = 0 ; 
    while (i < j) {

        int count = 0 ; // no matching pair found yet

        if (arr[i] + arr[j] == num ) {
            count++ ; // now 1st match is found  however we need to ensre if there is a repeat happening or not of the same element as the array is sorted
        } else if ( arr[i] + arr[j] > num ) {
            j-- ; // Now the sum is high and then the sum need to be low 
        } else {
            i++ ; // now the sum is low and 
        }

        if ( count == 1 ) {
            
            // Now we have to check what are the number of elements in the array and increment the i and j accordingly 
            while (  (arr[j] == arr[j-count])  &&  (i < j-count) ) {
                count ++ ;
            }
            PairCount += count ;

            /* now we can print the array elements if count is higher
            while ( count-- ) {
                cout << arr[i] << " " << arr[j] << endl;
            }
            */
            i++ ;
        }
    }
    return PairCount;
}

int tripletSum(int *arr, int n, int num)
{
    // Base Approach with very High Time Complexity of O (n^3)
	//MergeSort (arr ,0, n - 1) ; // now array is sorted
    //int i = 0 , j = i+1 ,k= n-1,TripletCount = 0 ; 
    int TripletCount = 0;

    for (int i = 0 ; i < n ; i++) { 
        for (int k = n-1 ; k > i ; k--) {
            for (int j = i+1 ;j < k ; j++) {
                if (arr[i] + arr [j] + arr [k] == num ) {
                    TripletCount ++ ;
                }
            }
        }
    }
    return TripletCount;
}

int tripletSum_2(int *arr, int n, int num) {
    int TripletCount = 0 ;
    MergeSort (arr ,0, n-1) ;

    for (int i = 0 ; i < n ; i++) {
        TripletCount += pairSum ( arr+i+1,n-i-1,num-arr[i] ) ;
    }
    return TripletCount;
}

int main() {
    int t ; 
    cin >> t; // no of test cases

    while (t--) {
        int size,num ;
        cin >> size; 
        int *Arr1 = new int [size];
        for (int i=0; i< size; i++) {
            cin >> Arr1[i];
        }

        cin >> num ;
        cout << tripletSum (Arr1, size, num)<< endl;
        cout << tripletSum_2 (Arr1, size, num)<< endl;

        delete[] Arr1;
    }
}