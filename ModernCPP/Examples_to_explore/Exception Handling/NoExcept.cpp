#include<iostream>
using namespace std;

//void fun(int x) throw()
void fun(int x) noexcept(true)
{
	cout << "can throw exception..." << endl;
	if (x == 0)
		throw x;
}

int main()
{
	try
	{
		fun(0);
	}
	catch (int y) { cout << "Exception int:" << y << endl; }
	return 0;
}