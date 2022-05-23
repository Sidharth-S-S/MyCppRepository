#include "iostream"
#include "cstring"
using namespace std;

/*
    Suppose you have a string, S, made up of only 'a's and 'b's.
    Write a recursive function that checks if the string was generated using the following rules:

    a. The string begins with an 'a'
    b. Each 'a' is followed by nothing or an 'a' or "bb"
    c. Each "bb" is followed by nothing or an 'a'

    If all the rules are followed by the given string, return true otherwise return false.
*/

bool checkAB(char input[]) {
	// base case:
    if (input[0] == '\0'){
        return true;
    }

    // small calculation ++ recursive call
    if (input[0] == 'a') {
        if (strlen(input) == 1){
            return true; // only a is there
        } else if (input[1] == 'a'){
            return checkAB(input + 1); // each a is followed by a  but we can check for the  abb  or the aabb -> abb type so again checking from +1
        } else if ((input[1] == 'b') && (strlen(input) > 2 ) && (input[2] == 'b')){
            return checkAB(input + 3) ;// a is followed by bb  then again check bb is followed by nothing or a 
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main(int argc, char **argv){
    char input[100000] ;
    cin >>input ;
    cout << boolalpha << checkAB(input) ;
}