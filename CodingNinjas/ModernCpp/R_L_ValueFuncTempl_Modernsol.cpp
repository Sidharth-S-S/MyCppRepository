
#include<iostream>
using namespace std;

//Modern solution using R value references in c++11 arrangment
template<typename T1, typename T2> void Wrapper(T1&& x, T2&& y)
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
     * Check the notebook for how the && is solving now , 
     * && + &  => & (any number of odd is 1)
     * && + && => &&  => 0 (any number of even is 0)
     * */ 
    return 0;
}