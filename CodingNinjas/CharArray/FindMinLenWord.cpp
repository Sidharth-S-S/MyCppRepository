#include <iostream>
using namespace std;
#include <cstring>
#include <climits>

void minLengthWord(char input[], char output[]){
    int StartIdx = 0 , EndIdx = 0 , MinLength = INT_MAX ;

    for (unsigned int i = 0 ; i <= strlen(input) ; i++){ /*considering the last index as '/0' appears at the last+1 idx */
        if ((input[i] == ' ') || input[i] == '\0') {
            EndIdx = i-1 ;
            int Length = EndIdx - StartIdx + 1 ;
            if (Length < MinLength){
                MinLength = Length ;
                for (int j = 0 ; j < Length ; j++){
                    output[j] = input[j+StartIdx];
                }
                output[Length] = '\0' ;
            }
            StartIdx = i+1 ;
        }
    }
}

int main() {
    char input[100000] = {'\0'}, output[100000]= {'\0'};
    cin.getline(input, 100000);
    minLengthWord(input, output);
    cout << output << endl;
}