#include <iostream>
using namespace std;

#include <cstring>

void helper_string(char input[]){
    // base case 
    // if the string starts not with 0 then also stop progressing
    if ((strlen(input) == 0 ) || ( int(input[0]) != 48 )) {
        return ;
    }

    // Recursion case
    helper_string(input+1) ;

    // simple calculation 
    // check if the current string is 0 then just shift the strings by 1 to left 
    if (int(input[0]) == 48 ) {
        
        for (unsigned int i = 0 ; i < strlen(input) ; i++ ) {
            // 0th idx is now the 1st idx ..  idx are preponed 
            input[i] = input[i+1] ;
        }

    }
}

int stringToNumber(char input[]) {
    // 00001234 => 1234 , perform the character migration 1st then you can convert to integer 

    helper_string(input) ; // change the input vector
    int Num = 0 ;

    for (unsigned int i = 0 ; i < strlen(input) ; i++) {
        Num = Num * 10 + (int(input[i]) - int('0')) ;
    }

    return Num ;

}

int main() {
    char input[50];
    cin >> input;
    
    cout << stringToNumber(input) << endl;
    cout << input << endl;
}