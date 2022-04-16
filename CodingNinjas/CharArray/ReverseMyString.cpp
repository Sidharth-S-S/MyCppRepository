#include <iostream>
#include <cstring>
using namespace std;

int StrActualLength(char *str){
    int count = 0 ; 
    while(str[count] != '\0'){
        count++ ;
    }
    return count ;
}

void reverseString(char *string , int len){

    for (int i=0; i < len/2 ; i++){
        // The last element is null string hence storing will be done  in other way .+
        char temp = string[i];
        string[i] = string[len-1 - i] ; 
        string[len- 1 - i] = temp ;
    }
    string[len] = '\0' ;
}

int main(){
	int T ;
    char myString[100000] ;
	cin >> T ;

	while(T--){
		cin >> myString ;
        
        // Find the Actual length of the string 
        int Length = StrActualLength(myString) ;

        // Reverse the String so that it can be used for comparison
        reverseString(myString , Length) ;
        cout << Length << endl << myString << endl ;
	}
}