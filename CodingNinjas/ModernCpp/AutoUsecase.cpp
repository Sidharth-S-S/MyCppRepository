#include<iostream>
using namespace std;
//Traditional C++ generic code

//GENERIC CODE AUTHOR...


//C++11 approach 
template<typename T1, typename T2> auto Add(T1 x, T2 y) -> decltype(x+y)
{
    return x+y;
}


/*
//c++14 approach
template<typename T1, typename T2> auto Add(T1 x, T2 y)
{
    return x+y;
}
*/
/*
D:\Learning\MyC++Try\MyCppRepository\CodingNinjas\ModernCpp\AutoUsecase.cpp:16:55: error: 'Add' function uses 'auto' type specifier without trailing return type
 template<typename T1, typename T2> auto Add(T1 x, T2 y)
                                                       ^
D:\Learning\MyC++Try\MyCppRepository\CodingNinjas\ModernCpp\AutoUsecase.cpp:16:55: note: deduced return type only available with -std=c++14 or -std=gnu++14

Build finished with error(s).

 *  The terminal process terminated with exit code: -1. 
 *  Terminal will be reused by tasks, press any key to close it. 
*/

//GENERIC CODE CONSUMER
int main()
{
    float x;
    x = Add(23.21f, 100);
    cout <<"x = " << x << endl;
    cout <<"***********" << endl;
    
    x = Add(100, 23.21f);
    cout <<"x = " << x << endl;

    return 0;
}