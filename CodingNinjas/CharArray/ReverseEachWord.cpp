#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAXLIM 1000000

void reverseEachWord(char input[]) {
    
    // fix the start idx = 0 . 
    // find space and j-1 will be end idx  
    // from end idx to start idx again reverse the characters as array if need be .

    int startidx = 0 , endidx = 0;

    for (unsigned int idx = 0; idx <= strlen(input) ; idx++){ /* <= as we need to find the last idx before null char */
        if (input[idx]==' ' || input[idx] == '\0' /* Consider to flip the word if the last chunk of word is found */){
            endidx = idx - 1 ;
            for (int j = 0 ; j <= (endidx-startidx)/2; j++){
                // Swap the elements
                int temp = input[j + startidx] ;
                input[j + startidx] = input[endidx - j];
                input[endidx - j] = temp ;
            }
            startidx = idx + 1 ; 
        }
    }
}

int main(){
    char input1[MAXLIM];
    // cin.ignore();
    cin.getline(input1, MAXLIM-1);

    reverseEachWord(input1);
    cout << input1 << endl;

}