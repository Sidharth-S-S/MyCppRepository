/*
Return Keypad Code 
Given an integer n, using phone keypad 
find out all the possible strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.
Note : 
1. The order of strings are not important.
2. Input and output has already been managed for you. 
You just have to populate the output array and return the count of elements populated in the output array.

Sample Input: 23
Mapping is like : 
2 : abc
3 : def
4 : ghi
5 : jkl 
6 : mno 
7 : pqrs
8 : tuv 
9 : wxyz 

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
using namespace std;
#include <cmath>
#include <string>

int keypad(int num, string output[]){
    // Base Case 
    if (num == 0 || num == 1) {
        output[0] = "";
        return 1;
    }
    // Recursion Case  
    // Assume that the substring  already gives the count and the number Output as well 
    // Let input is 23 => assume for 2/3 we have the output . 23 / 10 => 2 as input  and already we will have output and count 
    // 2 => 2/10 => 0 and output is ""
    // if the num is 2 then the output will be 1 * 3 ++ "" + a / b / c => 3 outputs .. 
    int PrevCount = keypad(num/10 , output);
    int MultiplyFactor = 1 ;
    // Simple Calculation
    //we need to append the respective character to the beginning / end of the output
    // For this i am creating a character array if 4 length and then filling it as per the requirement .
    string MappingArray = "" ;

    switch (num%10) {
    case 0 : 
        MultiplyFactor = 1 ;
        break ;
    case 1 :
        MultiplyFactor = 1 ;
        break ;
    case 2 :
        MultiplyFactor = 3 ;
        MappingArray = "abc" ;
        break ;
    case 3 :
        MultiplyFactor = 3 ;
        MappingArray = "def";
        break ;
    case 4 :
        MultiplyFactor = 3 ;
        MappingArray = "ghi";
        break ;
    case 5 :
        MultiplyFactor = 3 ;
        MappingArray = "jkl";
        break ;
    case 6 :
        MultiplyFactor = 3 ;
        MappingArray = "mno";
        break ;
    case 8 :
        MultiplyFactor = 3 ;
        MappingArray = "tuv";
        break ;
    case 7 :
        MultiplyFactor = 4 ;
        MappingArray = "pqrs";
        break ;
    case 9 :
        MultiplyFactor = 4 ;
        MappingArray = "wxyz";
        break ;
}

    // Create a MultiplyFactor-1 more copy as there are  MultiplyFactor copies needed for these keys
   // 1st create a copy and then append as the array contents would be changed while copying
    for (int j=1 ; j<MultiplyFactor ; j++){
        for (int i = 0; i < PrevCount ; i++) {
            output[ j*PrevCount + i] = output[i] ;
        }
    }

     // For each of the element start to append the Mapping array as this would be needed as a final string
    for (int j=0 ; j<MultiplyFactor ; j++){
        for (int i = 0; i < PrevCount ; i++) {
            output[ j*PrevCount + i] += MappingArray[j] ;
        }
    }

    return PrevCount * MultiplyFactor ;
}


int main(int argc, char **argv) {
    int num ;
    cin >> num ; 

    string * OutputStr = new string[100000] ;

    int count = keypad(num,OutputStr) ;
    cout << count << endl ; 
    for (int i = 0; i < count ; i++) {
        cout << OutputStr[i] << endl;
    }
    // Delete the sub sequence
    delete []OutputStr ;
}