#include<iostream>
using namespace std;

/*
    - An example on conversion function, i.e. overloading data-types [standard/user-defined] as
      function names is called conversion functions.
    
    - A conversion function does not take any known formal parameters, but does return a value of
      the type 'function-name'. As such, we are not supposed to explicitly state the return type of
      a conversion function.

*/

class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y){ }
    operator int();    
};

CA::operator int()
{
    cout <<"operator int called" << endl;
    return a+b;
}

//*********consumer code**************
int main()
{
    CA obj1(10,20);
    int x;
    //Approach-1

    x =(int) obj1;    //(or)  x = obj1; ===> x = obj1.operator int();
    cout <<"x =" << x << endl;
    cout <<"****************" << endl;
    //Approach-2
    cout << (int) obj1 << endl;   // cout << obj1.operator int() << endl;
    
    return 0;
}