#include <iostream>
#include <string.h>
using namespace std;

char get_mapping_fromNumericString(string NumericString) {
       // the input string will be 1  and output is a ; if it is 23 then output is w;
       // we will get Numeric string as input, we have to convert it to integer and then from that int again  we have to find the related characters
       int TenPlace = 0 ,UnitPlace = 0 ;
       if ( NumericString.size() > 1 ){
           TenPlace = int(NumericString[0]) - int('0');
           UnitPlace = NumericString[1] - int('0');
       } else {
           UnitPlace = NumericString[0] - int('0');
       }

       if ((TenPlace * 10 + UnitPlace) > 26 ) {
           return '\0' ;
       } else {
           return char(int('a') + -1 + (TenPlace * 10 + UnitPlace))  ;
       }   
}

void printAllPossibleCodes_helper(string input, string output){
    /********
     * The logic is that  1123 => 1 + 123 => 1 is the small calculation and recrsion will handle 123 ; 1 => a add it to output.  next recursion will handle (123,a)
     * Again we have to check if 11 + 23 is okay ; if 11 <= 26 then we need to call another recursion with   (23,k) 
     * base case , if the input is empty then print the output
     */

    if (input.empty()) {
        cout << output << endl;
        return ;
    }

    //printAllPossibleCodes_helper(input.substr(1), output + char(int('a') + stoi(input.substr(0,1)) - 1 ) ) ; // It works bt the order of the output is incorrect 
    printAllPossibleCodes_helper(input.substr( 0, input.length() - 1 ), char(int('a') -1 + stoi(input.substr( input.length() - 1,1)) ) + output ) ; 


    if ( input.size() > 1){
        if (stoi(input.substr( input.length() - 2,2)) <= 26) {
            //printAllPossibleCodes_helper(input.substr(2), output + char(int('a') + stoi(input.substr(0,2)) - 1 ) ) ;
            printAllPossibleCodes_helper(input.substr( 0, input.length() - 2 ), char(int('a') -1 + stoi(input.substr( input.length() - 2,2)) ) + output  ) ;
        }
    }

}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    e.g. : inp = 1123
    output will be the mapped array like aabc , alc , kbc,kw ,aaw  
    to print the array we have to consider the output array which will gradually store the result and append to it with each recursion
    */

   string output = "" ;
   printAllPossibleCodes_helper(input, output);

}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}