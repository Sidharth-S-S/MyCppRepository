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

void reverseString(char *string){
    int len = StrActualLength(string) ;

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
    const int MaxSize = 100000 ;
    char myString[MaxSize] = {'\0'}; ;
    // No of iteration
	cin >> T ;

	while(T--){
        // subtract 1 to allow null Character at end of array
        cin.ignore();
		cin.getline (myString,MaxSize-1,'\n') ;
        //cin >> myString ;
        
        // Reverse the String
        reverseString(myString) ;

        cout << myString << endl ;
	}
}