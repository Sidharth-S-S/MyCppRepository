#include<iostream>
using namespace std;
//Traditional C++ generic code

//GENERIC CODE AUTHOR...
template<typename T1, typename T2> T1 Add(T1 x, T2 y)
{
    return x+y;
}

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