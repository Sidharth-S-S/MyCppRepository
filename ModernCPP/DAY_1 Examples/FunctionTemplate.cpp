#include<iostream>
using namespace std;

//Traditional C++ generic code

//GENERIC CODE AUTHOR...
//template<typename T1, typename T2, typename T3> T3 Add(T1 x, T2 y)

template<typename T1, typename T2, typename T3> T1 Add(T2 x, T3 y)
{
    return x+y;
}


//GENERIC CODE CONSUMER
int main()
{
    float x;
    //x = Add<float,int,float>(23.21f, 100);  //Explicit instantiation

    x = Add<float>(23.21f, 100);  //Explicit cum implicit instantiation
    cout <<"x = " << x << endl;
    cout <<"***********" << endl;
    //x = Add<int,float, float>(100, 23.21f);
    
    x = Add<float>(100, 23.21f);
    cout <<"x = " << x << endl;
    return 0;
}
