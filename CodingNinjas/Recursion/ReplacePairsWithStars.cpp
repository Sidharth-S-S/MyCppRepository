#include <iostream>
using namespace std;

#include <cstring>

// Change in the given string itself. So no need to return or print the changed string.

void pairStar(char input[]) {
    // Write your code here
    unsigned int Len = strlen(input) ;

    // base case 
    // if the string starts not with 0 then also stop progressing
    if ((Len == 0 ) || (Len == 1 )) {
        return ;
    }

    
    // Recursion case // hello => ello will be the input and the output is already el*lo
    pairStar(input+1) ;

    // Simple Calculation 
    // if 0th idx = x and 1st is x then shift element 1 to n by 1 and add * at the 1st idx
    if (input[0] == input [1]) {

        for (unsigned int i = strlen(input) ; i >= 1 ; i-- ) {
            // Shift all the elements from idx 1 towards right by 1
            input[i+1] = input[i] ;
        }
        // Now add * to the 1st idx 
        input[1] = '*' ;
    }
}

int main() {
    char input[50];
    cin >> input;
    
    pairStar(input) ;
    cout << input << endl;
}