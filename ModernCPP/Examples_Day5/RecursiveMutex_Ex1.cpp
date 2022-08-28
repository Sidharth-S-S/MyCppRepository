#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mx;
std::recursive_mutex rmx;

void fun(int n) 
{
	//lock_guard<mutex> guard(mx);
	lock_guard<recursive_mutex> guard(rmx);
	cout << "value of n" << n << endl;
	if (n == 1)
	{
		cout << "-------------" << endl;
		return;
	}
	else
	{
		--n;
		fun(n);   //recursive call here
	}
}

int main()
{
	
	thread th1(fun,10);
	thread th2(fun, 20);

	th1.join();
	th2.join();
	return 0;
}