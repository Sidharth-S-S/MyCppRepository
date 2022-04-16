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

bool CheckPallindrome(char *string){
    bool isPallindrome = true ;
    int len = StrActualLength(string) ; 

    for (int i=0; i < len/2 ; i++){
        // The last element is null string hence storing will be done  in other way .+
        if ( string[i] != string[len-1 - i] ){
            isPallindrome = false ;
            break ;
        }
    }
    return isPallindrome ;
}

int main(){
	int T ;
    char myString[100000] ;
	cin >> T ;

	while(T--){
		cin  >> myString ;
        cout << boolalpha << CheckPallindrome(myString) ;
	}
}