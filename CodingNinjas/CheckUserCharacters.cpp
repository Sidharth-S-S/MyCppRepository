#include <iostream>
using namespace std; 
int main() {
    /* 
    Sample Input : abc def4 5$
    Sample Output : 6 2 2

        Sample Output Explanation :
        Number of characters : 6 (a, b, c, d, e, f)
        Number of digits : 2 (4, 5)
        Number of white spaces : 2 (one space after abc and one newline after 4)

    Write a program to count and print the 
        total number of characters (lowercase english alphabets only), 
        digits (0 to 9) and 
        white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.

    That is, input will be a stream of characters and you need to consider all the characters which are entered till '$'.
    Print count of characters, count of digits and count of white spaces respectively (separated by space).
    */
    int Count_char = 0 , Count_digit = 0 , Count_space = 0 ;
    char c ;
    c = cin.get();
    while (c != '$') {
        if (int(c) <= 57 && int(c) >= 48 ) {
            Count_digit++ ;
        } else if (c == ' ' || c == '\t' || c == '\n') {
            Count_space++ ;
        } else {
            Count_char++ ;
        }
        c = cin.get();
    }
    cout << Count_char << " " << Count_digit << " " << Count_space << endl ;
}