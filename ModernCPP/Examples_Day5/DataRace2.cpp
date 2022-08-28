#include<iostream>
#include<thread>
#include<mutex>  //synchronization primitive header

using namespace std;

std::mutex mx;

void Decrement()
{
	for (int i = -1; i > -100; i--)
	{
        mx.lock();
		cout << "Decrement :" << i << endl;
        //...
		mx.unlock();
	}
}

void Increment()
{
	for (int i = 1; i<100; i++)
	{
        mx.lock();
		cout <<"Increment :"<< i << endl;
		mx.unlock();
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