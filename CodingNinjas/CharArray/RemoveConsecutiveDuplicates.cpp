#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAXLIM 1000000

void removeConsecutiveDuplicates(char input1[]){

    char PrevChar = input1[0];
    int NextIdx = 1 ; // Storing the Result in the next Idx if we do not find a duplicate

    for (unsigned int i = 1; i < strlen(input1); i++){
        if (input1[i] != PrevChar ){
            input1[NextIdx] = input1[i];
            PrevChar = input1[i];
            NextIdx++;
        }
    }
    // Append Null Character at the end of the string 
    input1[NextIdx] = '\0';
}


int main(){
    char input1[MAXLIM];
    // cin.ignore();
    cin.getline(input1, MAXLIM-1);

    removeConsecutiveDuplicates(input1);
    cout << input1 << endl;

}