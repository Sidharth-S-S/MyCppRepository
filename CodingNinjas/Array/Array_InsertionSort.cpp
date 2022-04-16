#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/*  Insertion Sort Function
It is like inserting a card in it's proper position given the array size is changing consistently
Step 1 : Assume idx = 0 , element is correctly put in the array
Step 2 : Element at index 1 is now compared against idx0 , if Array[1] > Array[0] then break from the current loop
Step 3 : Element at index 2 is now compared against idx1 , if Array[2] > Array[1] then break from the current loop without any comparision.
        if Array[2] < Array[1] => Swap elements of 2 and 1 
        if Array[1] > Array[0] then break from the current loop else Swap elements of 1 and 0 .

Such loop is continued till the last element is found ; iterated from i = 1 .. (size-1)
For each i , j = 0 => i-1   iteration ,  Comparision starts with i-1 element  
                            if that element is smaller then break the loop else continue sorting the elements . 
*/

/* 
Logic : 
Current Element is Array[i] , 
Compare this element with each element from the previous index j = i-1 till j = 0 ; 
if         Array[j] > CurrentElement   ;  then Array[j+1] = Array[j]   (change the position of that array element by 1 )
keep on checking if j = 0 ; then Array[0] = CurrentElement 
else if  Array[j] < CurrentElement ; then also STOP and Assign Array[j+1] = CurrentElement
*/

void insertionSort(int *Array , int Size){
    for (int i = 1; i < Size;i++){
        int CurrentElement = Array[i],j ; 
        
        // Compare all the elements to the left of i and find which is lesser .
        for (j = i-1; j >=0 ; j--){
            if ( CurrentElement < Array[j]){
                // As the Current element is small , jth element has to shift right
                Array[j+1]  = Array[j] ;
            } else {
               break ;
            }
        }
        // Assign the Current Element now at the j+1 position , 
        // if the entire Array is traversed then j = -1 (Asign at j = 0th Position) 
        // else if break is used then (j = 2 element is small then assign at j = 3)
        Array[j+1]  = CurrentElement ;
    }
}


int main() {
    //     The first line contains an Integer 't' which denotes the number of test cases
    int t = 1 ,myArray1[100000];
    cin >> t ;

    for (int i = 1 ; i <= t ; i++) {
        int N  ;
        cin >> N ;
        for (int j = 0;j < N ; j++){
            cin >> myArray1[j] ;
        }
        insertionSort(myArray1, N) ;
        //directly print the original array as the changes happened at the memory directly .
        for (int j = 0;j < N ; j++) {
            cout << myArray1[j] << " " ;
        }
    }
}
