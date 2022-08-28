#include<iostream>
using namespace std;

//Modern C++ approach - REFERENCE COLLAPSING AND RVALUE REFERENCE TYPES....

//template<typename T1, typename T2> void Wrapper(T1& x, T2& y)  //Both LVALUE REFERENCE types

template<typename T1, typename T2> void Wrapper(T1&& x, T2&& y)  //Both RVALUE REFERENCE types
{
    cout << "x =" << x <<",y = " << y << endl;
}
/*
    With RVALUE reference types as formal parameters, there is no need to overload the same, as
    this single function would work or get instantiated suitably for any combination of inputs.
*/

//************consumer code ***********************
int main()
{
    /*
        Here 'a' and 'b' are LVALUE types,
        whereas 10 and 45.12f are RVALUE types.
    */
    int a=10;
    float b = 45.12f;

    //Make a call to the 'Wrapper' function with all LVALUE types
    Wrapper(a,b);
    //Make a call to the 'Wrapper' function with an combination of LVALUE, RVALUE
    Wrapper(a, 45.12f);
    //Make a call to the 'Wrapper' function with an combination of RVALUE, LVALUE
    Wrapper(10,b);
    //Make a call to the 'Wrapper' function with all RVALUE types
    Wrapper(10,45.12f);

    return 0;
}