#include<iostream>
using namespace std;

int main()
{
    const int a=10,b=20;
    cout <<"main::a " << &a << endl;
    cout <<"main::b " << &b << endl;

    auto lm1=[=]() mutable 
    {
        a=a+100;  //changes not allowed to locally captured elements, as the original outer-scope
        b=b+100;  //elements are read-only - here 'mutable' has no impact.
        cout <<"inside lambda, a= " << a << ", its address =" << &a <<  endl;
        cout <<"inside lambda, b=" << b << ", its address = " << &b << endl;
   };

    lm1();
   return 0;
}