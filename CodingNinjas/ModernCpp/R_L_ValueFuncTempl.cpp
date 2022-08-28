#include<iostream>
using namespace std;

//Issues with the generic function, whose formal parameters are reference types in TRADITIONAL C++
template<typename T1, typename T2> void Wrapper(T1& x, T2& y)
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

    /***
     * The above combinations of RVALUE and LVALUE are not supported due to the address  as parameter in the function template <typename T1, typename T2> 
     * Heterogenous types are ignored actually.
     * T1& x  => int ++ T2& y => float for call one =>   int& x , float& y  => x is an alias to the integer and y is an alias to the float variable.
     * now for case 1 , int& x = a ; float& y = b ;;;;
     * Case2 => int& x = a ; float& y = 32.26f => now the right handside is not a variable but a constant hence the error .
     * Case3 => int& x = 32 ; float& y = b ; Error due to constant value as reference
     * Case4 => int& x = 12 ; float& y = 13.32f => Constant reference is not supported as alias .
     * We can not handle the constant references 
     * */
   
    return 0;
}