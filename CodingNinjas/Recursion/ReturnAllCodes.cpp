#include <cstring>
#include "iostream"
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

int getCodes(string input, string output[10000]) {
    /*
    Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
    You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
    Note : The order of codes are not important. And input string does not contain 0s.
    
    Input format :  A numeric string

    Constraints : 
    1 <= Length of String S <= 10
    Sample Input: 1123 

    Sample Output: 
    aabc
    kbc
    alc
    aaw
    kw
    */

   // base case scenario 
   if (input.empty()) {
       output[0] = '\0';
       return 1 ;
   }

   // recursion will handle everything assume 
   int PrevCount = getCodes(input.substr(1), output) , PrevCount_2 = 0 ;

   // Small calculation
   // in all the prev count we have to add 1st character of input string
   for (int i = 0; i < PrevCount ; i++) {
       // Output array will contain already the elements of interest
       output[i] = get_mapping_fromNumericString(input.substr(0,1)) + output[i] ;
   }

   // now we need to also verify if there is a chance of combining the 1st 2 characters

   if ( input.size() > 1){
    if (get_mapping_fromNumericString( input.substr(0,2)) != '\0' ) {
       // 1ST 2 CHARACTERS CAN BE combined together
       // recursion will handle everything except the 1st 2 characters
       string output1[1000] ;
       PrevCount_2 = getCodes(input.substr(2), output1) ;

       for (int i = PrevCount; i < PrevCount + PrevCount_2; i++) {
       // Output array will contain already the elements of interest
       output[i] = get_mapping_fromNumericString(input.substr(0,2)) + output1[i-PrevCount] ;
       }
    }
   }
   return (PrevCount + PrevCount_2 );
}