#include <iostream>
using namespace std;

#include <cstring>

bool helper_checkPalindrome(char input[],unsigned int start,unsigned int end){
    if ( start >= end ) return true ;

    // simple calculation
    if ( input[start] != input[end] ) return false ;

    // recursion
    return helper_checkPalindrome(input,start+1,end-1) ;
}

bool checkPalindrome(char input[]) {
    // Base Case
    unsigned int size = strlen(input) ;
    if ( size == 0 || size == 1 ) {
        return true;
    } else {
    // Simple Calculation
    //Recursion Case
    // Here we need to compare the index from beginning of input and end of input 
    // better to create a helper function now that would take
    return helper_checkPalindrome(input,0,size-1);
    }
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}