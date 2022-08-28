#include<iostream>
#include<thread>
using namespace std;

void Decrement()
{
	for (int i = -1; i > -100; i--)
	{
		cout << "Decrement :" << i << endl;
		//this_thread::sleep_for(1s);
	}
}

void Increment()
{
	for (int i = 1; i<100; i++)
	{
		cout <<"Increment :"<< i << endl;
		//this_thread::sleep_for(1s);
	}
}

int main()
{
	thread th1(&Increment);
	thread th2(&Decrement);
	//..
	th1.join();
	th2.join();

	return 0;
}