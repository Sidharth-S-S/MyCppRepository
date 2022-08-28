#include<iostream>
#include<tuple>
#include<map>
#include<vector>
using namespace std;


int main()
{
    vector<pair<string,string>> v1 ={{"- C++17 -","- standard -"},{"- structured -","- binding -"}};
    
    for(auto& val:v1)
    {
        cout << val.first << "," << val.second << endl;
    }

    //A simpler approach - C++17 structured binding
    for(auto&[first,second]:v1)
    {
        cout << first << ","<< second << endl;
    }
    return 0;
}