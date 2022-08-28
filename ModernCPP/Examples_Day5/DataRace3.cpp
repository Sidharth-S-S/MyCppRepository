#include<iostream>
#include<thread>
#include<mutex>  //synchronization primitive header

using namespace std;

std::mutex mx;

void Decrement()
{
    lock_guard<std::mutex> guard(mx);
	for (int i = -1; i > -100; i--)
	{
		cout << "Decrement :" << i << endl;
        //..
	}
}

void Increment()
{
    lock_guard<std::mutex> guard(mx);
	for (int i = 1; i<100; i++)
	{
		cout <<"Increment :"<< i << endl;
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