#include<iostream>
using namespace std;

int main()
{
    int a = 10 , b = 10 ;

    auto lm = [&] ()
    {
        a += 100 ;
        b += 100 ; 
        cout << "Inside the lambda function " << a << endl;
        cout << "Inside the lambda function " << b << endl;
    } ;

    lm(); 

    cout <<"contents of the local variables after calling lambda function" << endl;
    cout <<"inside main, a= " << a << endl;
    cout <<"inside main, b=" << b << endl;
}