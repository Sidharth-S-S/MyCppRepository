#include<iostream>
using namespace std;

//Issues with the generic function, whose formal parameters are reference types in TRADITIONAL C++

template<typename T1, typename T2> void Wrapper(T1& x, T2& y)  // for the LVALUE,LVALUE types
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

    // make a call to the 'Wrapper' function with combinations of RVALUE  and LVALUE types
    Wrapper(a,32.26f) ;

     // make a call to the 'Wrapper' function with combinations of RVALUE  and LVALUE types
    Wrapper(32,b) ;

     // make a call to the 'Wrapper' function with combinations of RVALUE  and LVALUE types
    Wrapper(12,13.32f) ;

    return 0;
}

/* ----------------------------------------------------------------
This is the issue in traditional implementation where for 2 combinations of RVALUE and LVALUE we give 4 template functions 
when 3 parameters are specified then we need to provide 9 template functions ... */