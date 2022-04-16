#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/*  Binary Search Algorithm

The Array has to be sorted before performing the binary search. 
Step 1 : Find the Middle Element of the Array by start = 0 ; end = n-1 (size - 1)
Step 2 : Now Compare the Search Number against mid element ; if greater then start = mid-element + 1 ; else end = mid-element - 1
Step 3 : Now Repeat the process till the start and end element are not equal or start <= end 
Step 4 : if the element is still not found then return -1 

default return -1  else return the index 

*/

int binarySearch(int *Array , int Size , int SearchElem){
    int start = 0 , end = Size -1 ;
    while ( start <= end ){
        int mid = (start + end)/2;
        if ( Array[mid] == SearchElem ){
            return mid ; // return as the element is found and the search is over
        } else if ( SearchElem >  Array[mid] ){
            start = mid + 1 ;
        } else {
            end = mid - 1 ;
        }
    }
    return -1 ;
}


int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray1[100000];
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N , SearchNum ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }
        /*
        cin >> M ;
        for (int j = 0;j < M ; j++){
            cin >> myArray2[j] ;
        }
        */
       cin >> SearchNum ; 
        cout << binarySearch(myArray1, N , SearchNum) << endl ;
        //directly print the original array as the changes happened at the memory directly .
        /*for (int j = 0;j < N ; j++) {
            cout << myArray1[j] << " " ;
        } */
    }
}
