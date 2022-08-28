#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

void print1(int x){cout <<x <<",";}
void print2(char x){cout <<x <<",";}

int main()
{
    list<int> ls1 ={10,20,30,40,50,60,70,80,90,100};  //uniform initialization syntax
    vector<char> v1 ={'a','b','c','d','e'};


    //Traditionally to traverse the list or vector container using a simpler syntax was for_each
    for_each(ls1.begin(), ls1.end(), print1);
    cout << endl << "********************" << endl;
    for_each(v1.begin(), v1.end(), print2);


    for(int x: ls1)
    {
        cout << x <<",";
    }

    cout << endl;
    for(char x: v1)
    {
        cout << x <<",";
    }
    cout << endl;

    return 0;
}