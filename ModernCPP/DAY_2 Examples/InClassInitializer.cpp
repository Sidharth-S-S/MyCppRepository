#include<iostream>
using namespace std;
/* In class initializers, applicable only for non-static data members of the class  */
class CA
{
private:
	int a{};
	int b{ 20 };
	float c = 12.34f;
	int sum = a + b;
	double val = compute();
public: 

	//The compiler would induce a default constructor on our behalf, and consider
	// the values provided in the class declaration, SUBJECT TO NO CONSTRUCTORS ARE
	// EXPLICITLY DEFINED BY THE PROGRAMMER.
/*
	CA():a(0),b(20),c(12.34f),sum(a+b), val(compute())
	{

	}
*/
                   //ADDED BY THE COMPILER ON OUR BEHALF
	CA()   /*  :a(0),b(20),c(12.34f),sum(a+b), val(compute())  */
	{
		cout <<"CA default constructor" << endl; 
	}

                       //ADDED BY THE COMPILER ON OUR BEHALF
	CA(int x):a(x)  /* , b(20), c(23.34f), sum(a+b), val(compute())   */
	{
		cout <<"CA one arg. constructor" << endl;
	}

	double compute()
	{
		return c * 45.56;
	}
	void print()
	{
		cout << "a =" << a << endl;
		cout << "b =" << b << endl;
		cout << "c =" << c << endl;
		cout << "sum =" << sum << endl;
		cout << "val =" << val << endl;
	}
};
//------------------
int main()
{
	CA obj1;
	obj1.print();
	CA obj2(100);
	obj2.print();
	return 0;
}