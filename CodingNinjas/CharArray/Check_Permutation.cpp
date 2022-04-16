#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAXLIM 1000000
bool isPermutation(char input1[], char input2[]){

    if (strlen(input1) == strlen(input2)){
        int FrequencyArray[255] = {0}; // frequence array size is kept at 255 so that each character can be stored at respective ASCII positions
        
        for (unsigned int i = 0; i < strlen(input1) ; i++){
            FrequencyArray[int(input1[i])] += 1 ; // increase the place value by 1 
        }

        for (unsigned int i = 0; i < strlen(input2) ; i++){
            FrequencyArray[int(input2[i])] -= 1 ; // now decrease from the same place as the character is found in string 2  
        }

        for (unsigned int i = 0 ; i < 255 ; i++) {
            if (FrequencyArray[i] != 0 ){
                return false;
            }
        }

        return true; // every element matches from the frequency array 
    }
    return false;
}

int main(){
    char input1[MAXLIM],input2[MAXLIM];
    // cin.ignore();
    cin.getline(input1, MAXLIM-1);
    cin.getline(input2, MAXLIM-1);

    cout << input1 << " & " << input2 << " After Comparison : " << endl;

    cout << boolalpha << isPermutation(input1, input2) << endl;

}