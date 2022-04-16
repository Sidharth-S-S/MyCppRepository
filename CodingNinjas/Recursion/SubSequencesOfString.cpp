/*
Print the sub sequence of the array  
string s1 = "abc" , then it would be showing as 
" " / a / b / c / ab / ac / bc / abc  =>  output will be 8 2 ^ 3  
*/
#include <iostream>
using namespace std;
#include <cmath>

int getSubSequence(string InputStr, string * OutputStr){
    // Subsequence Base Case
    if ( InputStr.empty() ) {
        OutputStr[0] = "";
        return 1;
    }

    // assume now that if the string is   abc  then for the substring  bc 
    // already the sub sequence are available 
    int PrevCount = getSubSequence(InputStr.substr(1),OutputStr);

    // Small Calculation Once the bc => stuffs found . 
    // Now we will have 2^2 = 4 output ; 
    // another 4 elements to be added again by concatenating 1st element to the already output 
    for (int i = 0; i < PrevCount; i++ ) {
        OutputStr[PrevCount + i] = InputStr[0] + OutputStr[i] ;  
    }
    return PrevCount * 2 ; // It will be double 
}

int main(int argc, char **argv) {
    string s1 ;
    getline(std::cin, s1);
    int MyLen = pow(2,s1.size()) ; 

    string * OutputStr = new string[MyLen] ;

    int count = getSubSequence(s1,OutputStr) ;
    for (int i = 0; i < count ; i++) {
        cout << OutputStr[i] << endl;
    }

    // Delete the sub sequence
    delete []OutputStr ;
}