/* Print the Subsequences of a string .
You do not have to store them just print the subsequences 
e.g.  ab =>  either include a or b or both or none ; 
ab => b => ""  as output or "" + b
then ab => "" + ""   or   "" + a  or b + "" or b + a   
output for none case = blank "" + 

So for a string it would be 2 cases  output & output + input[0]
and if the input is empty then return the output directly (no need to return here just print)
*/
#include "iostream"
#include "cstring"
using namespace std;

void PrintSubsequences(string input, string output){
    // base case when the input is empty
    if (input.empty()){
        cout << output << endl;
        return;
    }

    // Simple Calculation Directly Print but current logic is that we will keep on trimming the string down 
    // e.g.  input ==  ab => b => ""  when input is empty then just print output , which will be empty to start
    PrintSubsequences(input.substr(1) , output)  ; // Just pass the output as it is and then pass the output +  input[0]
    PrintSubsequences(input.substr(1) , output + input[0])  ; // e.g.  ab -> b as input  ( output + input[0] (a) )

    return ;
}

int main(int argc, char **argv){
    string input ;
    getline(std::cin, input);
    //print the output of the string
    string output = "";
    PrintSubsequences(input, output) ;
}

/* Dry Run Subsequences
input : abc 
abc //  (bc , "")  &&  (bc , a) // bc -> (c,"") & (c,b) 
// (c,"") -> ("","") , ("",c)
Print : "" // c
// (c,b) // ("",b) ++ ("" , bc)
Print : b , bc
(bc , a) => //  (c,a) & (c,ba) // (,a) & ("",ac) ...... 
*/