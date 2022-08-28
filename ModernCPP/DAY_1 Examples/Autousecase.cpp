#include<iostream>
using namespace std;

//Modern C++ generic code

//GENERIC CODE AUTHOR...

//template<typename T1, typename T2, typename T3> T1 Add(T2 x, T3 y)

/*
//C++11 approach
template<typename T1, typename T2> auto Add(T1 x, T2 y)   ->decltype(x+y)
{
    return x+y;
}
*/

//C++14 approach
template<typename T1, typename T2> auto Add(T1 x, T2 y)   
{
    return x+y;
}

//GENERIC CODE CONSUMER
int main()
{
    float x;
    //x = Add<float>(23.21f, 100);  //Explicit cum implicit instantiation

    x = Add(23.21f, 100);  
    cout <<"x = " << x << endl;
    cout <<"x = " << x << endl;
    cout <<"***********" << endl;
    //x = Add<float>(100, 23.21f);

    x = Add(100, 23.21f);
    cout <<"x = " << x << endl;
    return 0;
}
