#include<iostream>
using namespace std;

//Issues with the generic function, whose formal parameters are reference types in TRADITIONAL C++

template<typename T1, typename T2> void Wrapper(T1& x, T2& y)  //Both LVALUE types
{
    cout << "x =" << x <<",y = " << y << endl;
}


template<typename T1, typename T2> void Wrapper(T1& x, const T2& y)  //for LVALUE, RVALUE types
{
    cout << "x =" << x <<",y = " << y << endl;
}

template<typename T1, typename T2> void Wrapper(const T1& x, T2& y)  //for RVALUE, LVALUE types
{
    cout << "x =" << x <<",y = " << y << endl;
}

template<typename T1, typename T2> void Wrapper(const T1& x, const T2& y) //for both as RVALUE types
{
    cout << "x =" << x <<",y = " << y << endl;
}
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