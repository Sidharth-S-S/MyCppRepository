/*----------------------------------------------------------------
Write a program that takes a character as input and prints either 1, 0 or -1 according to the following rules.
1, if the character is an uppercase alphabet (A - Z)
0, if the character is a lowercase alphabet (a - z)
-1, if the character is not an alphabet
----------------------------------------------------------------*/
#include<iostream>
using namespace std;

int main() {
	// Write your code here
    char c;
    // Consider input character as c  which will  be sent by the user. 
    cout << "Enter Any Single Character to get the following output ;1, if the character is an uppercase alphabet (A - Z) . 0, if the character is a lowercase alphabet (a - z) ; -1, if the character is not an alphabet" << endl;
    cin >> c;
    int c1 = c; //convert the character into ASCII then perform the rangebound check
    //ASCII 65 - 90 stands for uppercase letters
    if ( c1>=65 && c1<=90 ) {
        cout << 1 << endl;
    } else if ( c1>=97 && c1<=122 ){
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
	
}