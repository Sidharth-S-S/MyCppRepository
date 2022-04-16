#include <iostream>
#include <cstring>
using namespace std;


#define MAX_SIZE 1000000

int StrActualLength(char *str){
    int count = 0 ; 
    while(str[count] != '\0'){
        count++ ;
    }
    return count ;
}

void reverseStringWordWise(char input[]) {
    // Write your code here
    int Length = StrActualLength(input) ;
    char output[MAX_SIZE] = {'\0'} ;
    
    // Reverse the array e.g.    abc d efg hi =>  hi efg d abc  
    // Logic is 1st reverse the array ... => ih ghf d cba , now fix the start idx = 0 . 
    // find space and j-1 will be end idx ..  from end idx to start idx again reverse the characters as array if need be .
    
    for (int i = 0; i < Length ; i++){
        output[i] = input[Length - 1 - i] ;
    }
    
    int startidx = 0 , endidx = 0;

    for (int idx = 0; idx <= Length; idx++){
        if (output[idx]==' ' || output[idx] == '\0' /* Consider to flip the word if the last chunk of word is found */){
            endidx = idx - 1 ;
            for (int j = 0 ;j <= (endidx-startidx)/2;j++){
                // Swap the elements
                int temp = output[j + startidx] ;
                output[j + startidx] = output[endidx - j];
                output[endidx - j] = temp ;
            }
            startidx = idx + 1 ; 
        }
    } 

    //Reassign the array to the input array
    for (int i = 0;i<Length ; i++){
        input[i] = output[i];
    }
}

int main(){
	int T ;
    char myString[MAX_SIZE] = {'\0'}; ;
    // No of iteration
	cin >> T ;

	while(T--){
        // subtract 1 to allow null Character at end of array
        cin.ignore();
		cin.getline (myString,MAX_SIZE-1,'\n') ;
        //cin >> myString ;
        
        // Reverse the String
        reverseStringWordWise(myString) ;

        cout << myString << endl ;
	}
}