#include <iostream>
#include <cstring>
#include<string>
using namespace std;

string getCompressedString(string &input) {
    // aaabbcddeeeee   :   a3b2cd2e5
    // In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 'c' is occuring single time, 'd' is repeating 2 times and 'e' is repeating 5times.
    int Count = 1 ;
    char PrevChar = ' ' ;
    string s2 = "";
    
    
    for (unsigned int i = 0; i < input.length() ; i++) {
        char CurrentChar = input.at(i) ;
        
        if (CurrentChar == PrevChar){
            Count++;
            continue ;
        }
        if (Count > 1) {
            s2.push_back( char(int('0')+Count) ) ;
        }
        Count = 1 ; 
        s2.push_back(CurrentChar) ;
        PrevChar = CurrentChar ;
    }
    // if the last character is repeating then it wont be pushed back 
    if (Count > 1) {
        s2.push_back( char(int('0')+Count) ) ;
    }
    return s2 ;
}


int main() {
    string str;
    getline(cin, str);
    str = getCompressedString(str);
    cout << str << endl;
}