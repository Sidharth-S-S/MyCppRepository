#include<iostream>
using namespace std;

//Modern C++ approach - REFERENCE COLLAPSING AND RVALUE REFERENCE TYPES....

template<typename T1, typename T2> void Wrapper(T1&& x, T2&& y)  //Both RVALUE REFERENCE types
{
    x=x+100;
    y=y+200;

    cout << "Inside Wrapper, x =" << x <<",y = " << y << endl;
}


//************consumer code ***********************
int main()
{
   
    int a=10;
    float b = 45.12f;

    //Make a call to the 'Wrapper' function with all RVALUE types
    Wrapper(10,45.12f);
    cout <<"After Wrapper(10,45.12f), a= " << a <<",b=" << b << endl;
    cout <<"***************************" << endl;

    //Make a call to the 'Wrapper' function with all LVALUE types
    Wrapper(a,b);
    cout <<"After Wrapper(a,b), a= " << a <<",b=" << b << endl;
    cout <<"***************************" << endl;
    //Make a call to the 'Wrapper' function with an combination of LVALUE, RVALUE
    Wrapper(a, 45.12f);
    cout <<"After Wrapper(a,45.12f), a= " << a << ",b=" << b <<  endl;
    cout <<"***************************" << endl;

    //Make a call to the 'Wrapper' function with an combination of RVALUE, LVALUE
    Wrapper(10,b);
    cout <<"After Wrapper(10,b), a= " << a << ",b=" << b << endl;
    cout <<"***************************" << endl;
    
    return 0;
}