#include <iostream>
using namespace std;


int main(){
    char Str[] = "hello" ;
    char *pstr = &Str[0];

    cout << Str << endl ;  // hello
    cout << pstr << endl ; // hello
    cout << *pstr << endl ; // h

    char mydummy = 'a' ;
    char * pc = &mydummy ;
    cout << *pc << endl ; // a 
    cout << pc << endl ;  // a + garbage value // avoid this  
}