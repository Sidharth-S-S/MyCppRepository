#include<iostream>
using namespace std;

/*
    - C++17 approach - FOLD EXPRESSIONS
*/

int main()
{   
    //Variadic lambda - C++14
	auto varLambda = [](auto... Args)
	{
		auto lm =[](auto& x){cout << x << endl;};  //C++14 -Generic lambda

        (lm(Args), ...);   //Fold over comma - C++17
	};

    varLambda(100,200,45.12f, 89.21, 'a', "variadic");
	return 0;
}