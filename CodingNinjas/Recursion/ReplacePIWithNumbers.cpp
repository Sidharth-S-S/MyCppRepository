#include <iostream>
using namespace std;

#include <cstring>

/*----------------------------------------------------------------
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 

Sample Input 1 :  xpix
Sample Output :   x3.14x
Sample Input 2 :   pipi
Sample Output :    3.143.14
*/

void replacePi(char input[]) {
    unsigned int StrLen = strlen(input);
    // Base case when length is 0 or 1 
    if ( StrLen == 0 || StrLen == 1 ) return ; //

    // Now Assume the Recursion is gonna give us the correct output  for the input : xpix :: 
    // 1st argument is simple calculation and rest is done automatically.  pix => 3.14x  
    replacePi(input+1) ;

    // Simple calculation  only when 1st 2 index is  pi else do not have to do anything . 
    if ( input[0] == 'p' && input[1] == 'i' ) {

        // if the 2 characters are pi  they have to be  3.14 which are 2 characters more . 
        // So string needs to be changed . 
        
        for ( unsigned int i = strlen(input)+1; i >= 2 /*again strlen as input might be changed & in condition 2 because idx 0 and 1 is pi*/ ; i-- ) {
            // shift the element by 2 characters
            input[i+2] = input[i] ;
        }
        
        input[0] = '3' ;
        input[1] = '.' ;
        input[2] = '1' ;
        input[3] = '4' ;
    }

}

int main() {
    char input[50];
    cin >> input;
    
    replacePi(input) ;
    cout << input << endl;
}