#include<iostream>
#include<vector>
using namespace std;

//perfect forwarding
void fun1(int& x)
{
    cout << "fun1(int& x) LVALUE called" << endl;
}

void fun1(int&& x)
{
    cout << "fun1(int&& x) RVALUE called" << endl;
}

template<typename T> void Wrap(T&& x)  // int&& &&x = 200;  int && x=200;   int x=200
{
    //..some custom business inside the Wrap function...
    //... and later... a call to 'fun1' function...  if the original recieved value is R then accordingly it will go to R value fun1 else to L Value
    
    fun1(x);  // always L value as int x = 200 or int& x = a ;
    
    fun1(std::forward<T>(x));  //perfect forwarding...
}

//consumer code------------
int main()
{
    int a = 100;
    //fun1(a);    //fun1(int& x) LVALUE called 
    //fun1(200);  //fun1(int&& x) RVALUE called
    
    Wrap(a);    //fun1(int& x) LVALUE called
    Wrap(200);  //fun1(int& x) LVALUE called  not  RVALUE fun1   
    //=>  it will go as R value then it will be recieved by x as int x = 200 ; x is not a RVALUE but it is LVALUE.
   // to solve this kind of issue we can use instead of fun1(x) with a keyword of forward keyword and it will decide the proper VALUE function
    return 0;
}