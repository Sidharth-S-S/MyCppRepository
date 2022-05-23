#include <iostream>
#include <string.h>
using namespace std;

void printPermutations_helper ( string input , string output) {

    // base case
    if (input.empty ()) {
        cout << output << endl;
        return;
    }

    // recursive function with small calculation
    /********
     * The logic to print the output is based on the logic that keep on appending the input element by element to the output array till input is empty. 
     * abc ->  output => 1st char = a + output &&  input => bc  
     * bc in recursion will be like   output + 1st char => a+b &&  input => c ===>  recrsion on c will be  ab+c && input => ""  now the abc will be printed in output.
     */

    int MyLength = input.length() ;

    for (int idx = 0 ; idx < MyLength ; idx++) {
        printPermutations_helper ( input.substr(0,idx) + input.substr(idx+1, MyLength-idx-1) , 
                                   output + input.substr (idx,1) 
                                   /*  append 1 of the element to the output array */ ) ;
    }

}

void printPermutations(string input){
    string output = "" ;
    printPermutations_helper(input, output) ;
}

int main(){
    string input , output[10000];
    cin >> input;

    cout << "New Output Just Print"<< endl;
    printPermutations (input); 
    return 0;
}