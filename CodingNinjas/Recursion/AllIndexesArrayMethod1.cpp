#include <iostream>
using namespace std;

int AllIndex(int input[],int size,int x, int Output[]){
    //Base Case: input if the size becomes 0 then the element is not found and return 0
    if (size == 0) return 0;

    // E.g. Arr is 5 6 5 5 6 , x = 5 . 2 ways this is possible 1 + n-1   or  n-1 + 1 
    // Assume Recursion is gonna give o/p for 6 5 5 6 (for x = 5) as 1 2 & size = 2 ;
    // Now Small Calculation will check if Arr[0] == x ? if yes 
    // then shift op array elements by 1 , element 0 of the output array will be 0 then 
    // If the element is not found or it is found then we have to increase the output element by 1 .

    int TempSize = AllIndex(input+1 , size-1,x,Output);

    // Increase each of the Array Element of Output by 1 
    for (int i = 0; i < TempSize; i++){
        Output[i] = Output[i] + 1;
    }

    // Small Calculation
    if (input[0] == x ){
        // Shift the array elements by 1 
        for (int i = TempSize; i >= 1  ; i--){
            // We need to Assign the Values from the reverse so that we do not loose the values
            // e.g.  if the Temp size = 3 ; arr[3] = arr[2] ; arr[2] = arr[1]  ;; vice versa would remove values .
            Output[i] = Output[i-1] ; 
        }
        Output[0] = 0 ; // 0th index 
        // Increase the Array Size by 1
        TempSize ++ ;
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