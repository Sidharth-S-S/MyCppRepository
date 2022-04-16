#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAXLIM 1000000

char highestOccurringChar(char input[]) {
    // Write your code here
    int FrequencyArray[30] = {0} , MaxNum = 0 ; // As all the elements are lowercase hence we just need 26 elements at max
    char MaxCharacter = '\0' ; // 

    for (unsigned int i = 0; i < strlen(input); i++) {
        FrequencyArray[int(input[i]) - int('a')] ++; // increase the frequency array element once a particular element is found
        if ( FrequencyArray[int(input[i]) - int('a')] > MaxNum ) {
            MaxNum = FrequencyArray[int(input[i]) - int('a')] ;
        }
    }
    // Now we need to retun the character which comes 1st in the array . We can compare the array element again

    for (unsigned int i = 0 ; i < strlen(input) ; i++){
        if (FrequencyArray[int(input[i])  - int('a')] == MaxNum ) {
            MaxCharacter = input[i]  ;
            break ;
        }
    }

    return MaxCharacter;

}

int main(){
    char input1[MAXLIM] ;
    // cin.ignore();
    cin.getline(input1, MAXLIM-1);

    cout << highestOccurringChar(input1) << endl;

}