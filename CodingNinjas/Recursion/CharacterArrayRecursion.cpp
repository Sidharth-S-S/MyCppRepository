#include <iostream>
using namespace std;
#include <cstring>


int GetStrLen(char input[]){

    //base case 
    if (input[0] == '\0') return 0;

    //recursive case 
    int PrevLen = GetStrLen(input+1);

    return PrevLen + 1 ; 

}

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

void replaceCharacter(char input[], char c1, char c2) {
    /*  Given an input string S and two characters c1 and c2, 
     *  you need to replace every occurrence of character c1 with character c2 in the given string.
     *  Input Format : 
     *  Line 1 : Input String S
     *  Line 2 : Character c1 and c2 (separated by space)
     *  Output Format : Updated string
     *  Constraints :  x <= Length of String S <= 10^6
     *  Sample Input : 
     *  abacd
     *  a x  
     *  Sample Output :  xbxcd
     */

    // Base case
    if (input[0] == '\0') return ;

    // Recursion Case Assume that all the stuffs are done for   n+1 characters  
    // Example :  abcabc a , x =>  bcabc // o/p is bcxabc 
    replaceCharacter(input+1,c1,c2);

    // Simple Calculation
    if (input[0] == c1){
        input[0] = c2 ;
    }
}

void removeConsecutiveDuplicates(char *input) {
    // Base case 
    if (input[0] == '\0') return ;

    // Recursive Call assume that the output of the string   
    //  aabbcdddeee => abbcdddeee (Input) => o.p is abcde
    removeConsecutiveDuplicates(input+1);
    // now 1st string as input and then compare  a vs a  
    if ( input[0] == input[1] ){
        // Now we have to move the Strings by 1 ; 1 -> 0 , 2 - > 1 ; len -> len-1 
        for (unsigned int i = 0; i < strlen(input); i++) {
            input[i] = input[i+1] ;
        }
    }
}

int main() {
    char myStr[100] ;
    //cin.ignore();
    cin.getline(myStr, 100);

    cout << "Length of the String is : "<< GetStrLen(myStr) << endl ; 
    //removeX(myStr);
    removeConsecutiveDuplicates(myStr);
    cout << myStr << endl ;

    // For the replace character function 2 more chars are needed
    /*
    char c1 , c2 ;
    cout << "Enter 2 characters" << endl ;
    cin >> c1 >> c2 ;
    replaceCharacter (myStr,c1,c2) ;
    cout << myStr << endl;
    */

}