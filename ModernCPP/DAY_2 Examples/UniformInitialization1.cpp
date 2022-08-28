#include<iostream>
using namespace std;

class CA
{
private:
    int a,b;
public:
    CA():a(0),b(0){cout <<"CA default constructor" << endl;}  
    CA(int x):a(x),b(x){cout <<"CA one arg constructor" << endl;}  
    CA(int x, int y):a(x),b(y){cout <<"CA two arg. constructor" << endl;}
    CA(const CA& x):a(x.a),b(x.b){cout <<"CA copy constructor..." << endl;}

    //..
    ~CA(){cout <<"CA destructor..." << endl;}
};

//*******class consumer **********
int main()
{
    //Traditional approach, where each object as part of the array would only call
    //the default constructor...
    CA* p1 = new(nothrow) CA[5];
    //..
    delete [] p1;
    cout <<"********************" << endl;
    //Modern approach, with brace initialization syntax we can provide individual parameters
    //for each object as part of the array.
    CA obj1;
    CA* p2 = new(nothrow) CA[5]{{},{100},{10,20},{200},{obj1}};
    //...
    delete [] p2;
    return 0;
}