#include <iostream>
using namespace std;

#include <cstring>

/*----------------------------------------------------------------
Given a string, compute recursively a new string where all 'x' chars have been removed.

Input format :  String S
Output format : Modified String
Constraints :  1 <= |S| <= 10^3   ;   where |S| represents the length of string S. 

Sample Input 1 :  xaxb
Sample Output 1:  ab
Sample Input 2 :  abc
Sample Output 2:  abc
Sample Input 3 :  xx
Sample Output 3:  
*/

void removeX(char input[]) {
    unsigned int StrLen = strlen(input);
    // Base case when length is 0 or 1 
    if ( StrLen == 0 ) return ; //

    // Recursion assume that output is correct already 
    // xaxb ::   i/p  to recursion is   axb :  output is ab .
    removeX(input+1) ;

    // simple calculation 
    // if the current idx  input[0] is x then remove it else continue 

    if ( input[0] == 'x' ) {
        for (unsigned int i = 0 ; i < strlen(input) ; i++ ) {
            // 0th idx is now the 1st idx ..  idx are preponed 
            input[i] = input[i+1] ;
        }
    }
}

int main() {
    char input[50];
    cin >> input;
    
    removeX(input) ;
    cout << input << endl;
}