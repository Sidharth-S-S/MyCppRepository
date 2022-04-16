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

void trimSpaces(char *string){
    int len = StrActualLength(string) , SpaceCount = 0 ;

    for (int i=0; i < len ; i++){
        if (string[i] == ' '){
            SpaceCount++;
            continue ;
        }
        string[i-SpaceCount] = string[i] ;
    }
    string[len - SpaceCount] = '\0' ;
}

int main(){
	int T ;
    const int MaxSize = 1000000 ;
    char myString[MaxSize] = {'\0'}; ;
    // No of iteration
	cin >> T ;

	while(T--){
        // subtract 1 to allow null Character at end of array
        cin.ignore();
		cin.getline (myString,MaxSize-1,'\n') ;
        //cin >> myString ;
        
        // Reverse the String
        trimSpaces(myString) ;

        cout << myString << endl ;
	}
}