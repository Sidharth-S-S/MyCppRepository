#include <iostream>
#include <map>
using namespace std;

map<string,char> keyMap;

int getCodes(string input, string output[10000]) 
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    char ch='a';
    for(int i=1;i<=26;i++,ch++)
        keyMap[to_string(i)]=ch;
    
    if(input=="")
    {
        output[0]="";
        return 1;
    }

    int smallOutput1=getCodes(input.substr(1),output);
    int smallOutput2=0;

    if(input.size()>1 && stoi(input.substr(0,2))<=26)
        smallOutput2=getCodes(input.substr(2),output+smallOutput1); 
         // start the saving of the array elements immediately after the smallOutput1 and then it would append on the top of another array

    int smallOutput=smallOutput1+smallOutput2;

    for(int i=0;i<smallOutput1;i++)
    {
        output[i]=keyMap[string(1,input[0])]+output[i];
    }

    for(int j=smallOutput1;j<smallOutput;j++)
    {   
        output[j]=keyMap[input.substr(0,2)]+output[j];
    }
    
    return smallOutput;    
}
int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}