#include<iostream>
using namespace std;

//A simple example on lambda function...

//GLOBAL LAMBDA FUNCTION
auto lm3 =[](int x, int y) ->void
{
    cout << __PRETTY_FUNCTION__ << endl;
    cout << __FUNCTION__ << endl;
    cout <<"global::lambda called, x= " << x <<",y=" << y << endl;
};

int main()
{
    //define a lambda without an handle, and invoke the same at the point of definition itself.

    []() ->void
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << __FUNCTION__ << endl;
        cout <<"main::Lambda without a handle name called..." << endl;
    }();

    cout <<"*************" << endl;
    //Define a lambda with a handle with local scope
    auto lm1 = []() ->void
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << __FUNCTION__ << endl;
        cout <<"main::lambda with handle [lm1] called..." << endl;
    };

    auto lm2 = [](int x) ->void
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << __FUNCTION__ << endl;
        cout <<"main::lambda with handle [lm2] called, x = " << x << endl;
    };

    lm1();
    lm2(600);

    //Invoke the global lambda function
    lm3(100,200);

    
    return 0;
}

/*

auto lm3 = ...;    ---> function<void(int,int)> lm3 = ...;
lm3(10,20);        ---> lm3.operator()(10,20);


auto lm1 = ...;  ---> function<void(void)> lm1 = ...;
lm1();           ---> lm1.operator()();

auto lm2 = ...;  ---> function<void(int)> lm2 = ...;
lm2(100);        ---> lm2.operator()(100);

*/