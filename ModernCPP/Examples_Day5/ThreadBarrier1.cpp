#include<iostream>
#include<thread>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	//A lambda that serves as thread parameter
	auto thread_func = []() {cout << "Thread, hello from lambda\n"; };

	//spawn multiple threads & populate the result in a vector container
	vector<thread> v1;
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(thread(thread_func));
	}

	cout << endl << "Thread, from main()\n";

	//A lambda that assists in a join
	auto thread_join = [](thread& th) {th.join(); };

	//lets create a barrier to join every thread inside the vector container.
	for_each(v1.begin(), v1.end(), thread_join);
	cout <<"Join completed..."<< endl;
	return 0;
}