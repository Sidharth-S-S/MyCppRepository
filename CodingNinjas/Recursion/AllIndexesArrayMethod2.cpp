#include <iostream>
using namespace std;

int AllIndex(int input[],int size,int x, int Output[]){
    //Base Case: input if the size becomes 0 then the element is not found and return 0
    if (size == 0) return 0;

    // E.g. Arr is 5 6 5 5 6 , x = 5 . 2 ways this is possible 1 + n-1   or  n-1 + 1 
    // This is the method for the n-1 + 1   division . 
    // Assume the Array Recursion takes input array as   5 6 5 5 , for x = 5 , returns 0 2 3 // size = 3 
    // now if the last element is not found then the same thing is answer 
    // Assume that x = 6 ; for 5 6 5 5 , o/p = 1 , size = 1 ; 
    // input[size-1] == x then size ++ and last element is appended with the size-1
    
    // Recursion
    int TempSize = AllIndex(input , size-1 , x, Output);

    // Small Calculation
    if (input[size-1] == x ){
        // last element has 1 match 
        TempSize ++ ;
        Output[TempSize-1] = size-1 ;
    }
    
    return TempSize;
}

int main(int argc, char **argv) {

    int n , x ;
    cout << "Enter the number of elements of the array . " << endl;
    cin >> n ;
    
    int * p_inputArr  = new int[n] ; 
    int * p_outputArr = new int[n] ;
    
    for (int i = 0; i < n; i++){
        cin >> *(p_inputArr+i) ; // better way is to use pa[i]
    }

    cin >> x ;

    // Get the size of the output array that we are getting as output , O/P array will be modified directly .
    int size = AllIndex(p_inputArr,n, x,p_outputArr) ;

    for (int i=0; i <size; i++){
        cout << p_outputArr[i] << " " ;
    }


    // Always Free the dynamic memory once allocated
    delete[] p_inputArr ;
    delete[] p_outputArr ;

    return 0;
}