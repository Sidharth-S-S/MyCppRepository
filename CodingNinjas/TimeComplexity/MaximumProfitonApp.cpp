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

int maximumProfit(int budget[], int n) {
    // Write your code here
    // Method 1 : assuming that each element of the array is the smallest and traversing through the array to find out the max element and keep on checking the max profit 
    // this approach is having O(n^2) time complexity
    // Method 2 : sort the array now and then  you know the elements greater or smaller easily 
    MergeSort(budget , 0,n-1) ; 
    int Profit = 0 ; //

    for (int i = 0; i < n; i ++){
        if ( budget[i] * (n-i) > Profit ){
            Profit = budget[i] * (n-i) ;
        }
    }
    return Profit ;
}

int main() {
    int n ,*input,i;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
