#include<iostream>
using namespace std;

int main()
{
    int a=10,b=20;

    auto lm1=[=]() mutable throw() ->void
    {
        a=a+100;
        b=b+100;
        cout <<"inside lambda, a= " << a << endl;
        cout <<"inside lambda, b=" << b << endl;
    };

    //call or invoke the lambda function
    lm1();   // lm1.operator()();

    cout <<"contents of the local variables after calling lambda function for the first time" << endl;
    cout <<"inside main, a= " << a << endl;
    cout <<"inside main, b=" << b << endl;
    cout <<"******************************" << endl;
    lm1();
    cout <<"contents of the local variables after calling lambda function for the second time" << endl;
    cout <<"inside main, a= " << a << endl;
    cout <<"inside main, b=" << b << endl;
    cout <<"******************************" << endl;

    return 0;
}