#include<iostream>
#include<functional> // due to function  use
using namespace std;

//the lambda handle 'fib' which by default has global scope is directly visible inside the
//lambda function, there is no need to capture the same. Even capturing it does not make any
//business sense. As capturing is always in the context of the OUTER-SCOPE elements, that is if
//this lambda function happens to be scoped inside another function and not in the global scope.

//GLOBAL LAMBDA FUNCTION

function<int(int)> Globalfib = [](int x)  ->int
{
    return x <= 2 ? 1 : Globalfib(x - 1)+ Globalfib(x - 2);
};

int main()
{
    /* LOCAL LAMBDA WHOSE SCOPE IS main */
    //define a recursive lambda
    /*
        - A scenario, where the type-inference keyword 'auto' would not compile, for the simple
          reason, the lambda is trying to capture the lambda handle itself, well before the lambda
          handle gets defined.
    */
    //auto fib = [&fib](int x)  ->int  {    return x <= 2 ? 1 : fib(x - 1) + fib(x - 2); };
   
    //Explicitly we have to define the lambda handle's type, by using the functional header and the
    //function class.
    function<int(int)> fib = [&fib](int x)  ->int  
    {    
        return x <= 2 ? 1 : fib(x - 1) + fib(x - 2); 
    };
    cout << fib(10) << endl;
    cout << "********************************" << endl;
    cout << Globalfib(10) << endl;

    return 0;
}