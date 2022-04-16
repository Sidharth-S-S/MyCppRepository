/*
Comman way to sort 2 different arrays is to merge them together in any 1 of the array and then use any of the sorting algorithm to sort the same. 
However we are already getting 2 arrays already sorted so it would be kind of a double effort for us .

a[0]  vs b[0] => goes to c[0] 
Let a[0] smallest then a current idx = 0 + 1 = 1 
a[1]  vs  b[0]  => let b[0] small then  b idx = 0 + 1 = 1 
a[1] vs b[1] => let b[1] small then b idx = 1 + 1 = 2 

This operation goes on till we reach end of either a or b . Rest all the elements you can copy from the other sorted array .
*/
#include <iostream>
using namespace std;

void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    //Sorted 2 Arrays have to be arranged in order . 
    int FirstIdx = 0 , SecondIdx = 0 ,ThirdIdx = 0;

    while ((FirstIdx < size1) && (SecondIdx < size2)){
        if (arr1[FirstIdx] < arr2[SecondIdx]){
            ans[ThirdIdx] = arr1[FirstIdx];
            FirstIdx++;
        }
        else {
            ans[ThirdIdx] = arr2[SecondIdx];
            SecondIdx++;
        }
        ThirdIdx++;
    }


    for (int i = ThirdIdx; i < size1+size2; i++) {
        if (FirstIdx == size1){
            // Third Idx will be filled now by the elements of the 2nd array remaining elements
            ans[i] = arr2[SecondIdx];
            SecondIdx++;
        }
        else {
            // Third Idx will be filled now by the elements of the 1st array remaining elements
            ans[i] = arr1[FirstIdx];
            FirstIdx++;
        }

    }

}

void printArray(int *Array , int Size){
    for (int i = 0 ; i < Size;i++){
        cout << Array[i] << " " ;
    }
    cout << endl;
}

int main(){
    int t , Array1[100000] = {0}, Array2[100000] = {0}, Array3[100000] = {0};
    cin >> t ; // number of Tests
    
    while ( t-- > 0 ) {
        int Size1 , Size2 ;
        
        cin >> Size1;
        for (int j = 0;j < Size1 ; j++){
            cin >> Array1[j];
        }
        
        cin >> Size2 ;
        for (int j = 0;j < Size2 ; j++){
            cin >> Array2[j];
        }

        merge(Array1, Size1, Array2,Size2, Array3);
        printArray(Array3,Size1+Size2);
    }
}