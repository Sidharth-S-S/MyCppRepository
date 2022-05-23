#include <iostream>
#include <string.h>
using namespace std;

int returnPermutations(string input, string output[]){
   	/********
    * The logic for permutation of input is that abc => recursion handle bc => output will be bc & cb ;;  now we have a  o/p will be  abc , acb ,,, next 
    * b + recursion handle ac => bac , bca , bcc 
    * c + recursion handle ab => cab , cba 
    * a + recursion handle bc =>  b + recursion c => c + rec "" => when input is empty then return 1 ; output will be [] 
    * 
    * Method 2  :  abc => a + recursion handle bc --->  bc cb ; now a will be kept in 1 of the 3 position   _b_c_ => length = 2 => a at ; idx = 0 , 1 , 2  
    * 
	*/
    if (input.empty()) {
        output[0] = "";
        return 1; //
    }
    int MyLength = input.length()  , PrevCount = 0 , Count = 0;

    for (int idx = 0; idx < MyLength; idx++) {
        Count = returnPermutations( input.substr(0,idx) + input.substr(idx+1, MyLength-idx-1) ,output + PrevCount) ;

        for (int j = PrevCount; j < PrevCount+Count; j++) {
            output[j] = input.substr(idx,1) + output[j] ;
        }
        PrevCount += Count ;
    }
    return PrevCount ;
}

int main(){
    string input , output[10000];
    cin >> input;

    int count = 0;
    count = returnPermutations(input,output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}