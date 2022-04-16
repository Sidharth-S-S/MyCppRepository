#include <iostream>
#include <cstring>
using namespace std;


#define MAX_SIZE 1000000

void printSubstrings(char input[]) {
    // Write your code here
    for (unsigned int i = 0; i < strlen(input); i++) {
        for (unsigned int j = i ; j < strlen(input); j++) {
            for (unsigned int k = i ; k <= j ; k++) {
                // excellent logic to figure out the i j k relation , good to write down and then figure out the logic
                cout << input[k] ;
            }
            cout << endl;
        }
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
        
        // Reverse the String and print as required
        printSubstrings(myString) ;

	}
}