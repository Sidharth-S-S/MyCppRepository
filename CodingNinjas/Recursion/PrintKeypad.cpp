#include "iostream"
#include "cstring"
using namespace std;

void printKeypad_helper(int num,string output){
    // base case of recursion
    if ((num == 0) || ( num == 1 )){
        cout << output << endl;
        return ;
    }

    // small calculation  assume the num% 10 as the decision maker
    // print the output array of keys   
   string MappingArray = "" ;
   int MultiplyFactor = 0 ;

    switch (num%10) {
    case 0 : 
        MultiplyFactor = 1 ;
        break ;
    case 1 :
        MultiplyFactor = 1 ;
        break ;
    case 2 :
        MultiplyFactor = 3 ;
        MappingArray = "abc" ;
        break ;
    case 3 :
        MultiplyFactor = 3 ;
        MappingArray = "def";
        break ;
    case 4 :
        MultiplyFactor = 3 ;
        MappingArray = "ghi";
        break ;
    case 5 :
        MultiplyFactor = 3 ;
        MappingArray = "jkl";
        break ;
    case 6 :
        MultiplyFactor = 3 ;
        MappingArray = "mno";
        break ;
    case 8 :
        MultiplyFactor = 3 ;
        MappingArray = "tuv";
        break ;
    case 7 :
        MultiplyFactor = 4 ;
        MappingArray = "pqrs";
        break ;
    case 9 :
        MultiplyFactor = 4 ;
        MappingArray = "wxyz";
        break ;
    }

    // Output is already updated now let 23 => for 2 recursion will give output updated
    for (int i = 0; i < MultiplyFactor ; i++){
        // recursion case
        printKeypad_helper(num/10,MappingArray[i] + output) ;
    }

}

void printKeypad(int num){
    string output = "" ;
    printKeypad_helper(num,output);
}

int main(int argc, char **argv){
    int num ;
    cin >> num ;
    printKeypad(num) ;
}