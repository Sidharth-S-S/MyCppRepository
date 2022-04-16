#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

/* Sum of Two Arrays
Send Feedback
Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. 
Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). 
The idea here is to represent each array/list as an integer in itself of digits N and M.
You need to find the sum of both the input arrays/list treating them as two integers and put the result in another array/list i.e. output array/list 
will also contain only single digit at every index.

Note:
The sizes N and M can be different. 
Output array/list(of all 0s) has been provided as a function argument. 
Its size will always be one more than the size of the bigger array/list. 
Place 0 at the 0th index if there is no carry. 

No need to print the elements of the output array/list.
Using the function "sumOfTwoArrays", write the solution to the problem and store the answer inside this output array/list. The main code will handle the printing of the output on its own.
*/

void reverseArray(int *Array,int size){
    for (int i = 0 ; i < size/2 ; i++){
        int temp = Array[i];
        Array[i] = Array[size-1-i] ;
        Array[size-1-i] = temp ;
    }
}

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
    //Write your code here
    
    int size3 = max(size1, size2) + 1 , carry = 0 , MinSize = min(size1, size2); // The size of the array is max of the size plus 1 

    //Reverse the array so that the calculation starts from idx 0th till end 
    reverseArray(input1,size1) ; 
    reverseArray(input2,size2) ;
    
    for(int i = 0; i < size3 ; i++) { // Come from the back side of the array 
        int Sum ; 

        if (i < MinSize){
            Sum = input1[i] + input2[i] + carry;
        } 
        else if (i < size3 - 1){
            int RemNum ;
            if (MinSize == size1){
                RemNum = input2[i] ;
            } else {
                RemNum = input1[i]  ;
            }
            Sum = RemNum + carry;
        } else if (i == size3 - 1){
            Sum = carry ;
        }

        if (Sum <= 9){
            output[i] = Sum ;
            carry = 0;
        } else {
            carry = 1;
            output[i] = Sum % 10;
        }
    }
    reverseArray(output,size3);
}

void printArray(int *Array , int Size){
    for (int i = 0 ; i < Size;i++){
        cout << Array[i] << " " ;
    }
    cout << endl;
}

int main() {
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

        sumOfTwoArrays(Array1, Size1, Array2,Size2, Array3);
        printArray(Array3,max(Size1,Size2)+1);
    }
}