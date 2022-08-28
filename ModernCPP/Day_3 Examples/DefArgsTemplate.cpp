#include<iostream>
#include<typeinfo>
using namespace std;

//Now in modern C++, we can also provide default arguments for formal parameters of a FUNCTION TEMPLATE

template<typename T=int> void Fun(T x=10)
{
    cout <<"data type of x :"<< typeid(T).name() <<endl;
    cout <<"x = " << x << endl;
}

//*********consumer code *************
int main()
{
    Fun();
    Fun(45.12f);
    Fun(78.21);
    Fun('r');

    return 0;
}