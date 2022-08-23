#include<iostream>
using namespace std;
/*
    - Now in modern C++11, we can also inherit constructors of the
      base class onto the derived class.
*/

class Base
{
public:
    Base()
    {
        cout <<"Base default constructor..." << endl;
    }
    
    Base(int x)
    {cout <<"Base one arg. constructor..." << endl;}
    
    Base(int x, int y)
    {cout <<"Base two arg. constructor..." << endl;}
};


class Derived:public Base
{
public:
    using Base::Base;

    // this is useful when we have to use the derived class on the top of the base class to add more functionality  then change the way we define the constructor
    Derived(int x):Base(x)
    {
        cout <<"Derived one arg. constructor..." << endl;
    }

};


//**consumer code***
int main()
{
    Derived obj1;
    Derived obj2(100);
    Derived obj3(10,20);
    return 0;
}