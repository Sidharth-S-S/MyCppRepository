#include<iostream>
#include<thread>
using namespace std;

void Process1()
{
	this_thread::sleep_for(chrono::milliseconds(10));
	cout << "Executing Process1" << endl;
}

void Process2(thread th)
{
	th.join();
	cout << "Executing Process2, Completing Process1 thread" << endl;
}

int main()
{
	thread t1(Process1);
	/*
		- The independant child thread 't1' is now moved to another thread 't2'
		- The thread owned by 't1' is getting transferred or moved to other
		  child thread 't2'. [t2 is taking ownership of t1 thread]
	*/
	thread t2(Process2, std::move(t1));
	//....
	t2.join();
	return 0;
}