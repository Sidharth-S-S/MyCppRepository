#include<iostream>
#include<string>
#include<map>
#include<memory>
using namespace std;

class Outer
{
private:
	map<int, string> map_obj = { {10,"Ten"},{20,"Twenty"},{30,"Thirty"},{40,"Forty"},{50,"Fifty"} };
public:
	Outer() = default;

	void print()
	{
		cout << "Outer class, print called" << endl;
		for (auto x : map_obj)
		{
			cout << x.first << "," << x.second << endl;
		}
		cout << endl;
	}
	//**** Nested class ****
	class Inner   //- By default friend to Outer
	{
	private:
		unique_ptr<Outer> ptr;
	public:
		Inner() :ptr{ make_unique<Outer>() } {}
		Outer& Get() { return *ptr; }
		auto begin() { return ptr->map_obj.begin(); }
		auto end() { return ptr->map_obj.end(); }
	};
};


//****consumer code**************
int main()
{
	Outer::Inner Inner_data1;
	/* C++98 style */

	//auto Outer_data1( Inner_data1.Get() );
	//Outer_data1.print();

	/*  C++11/14 style, range-based loop */
	/*for (const auto& x : Inner_data1)
	{
		cout << x.first << "," << x.second;
		cout << endl;
	}*/

	/* C++17 style, structured binding with range-based loop */
	for (const auto& [key, data] : Inner_data1)
	{
		cout << key << "," << data;
		cout << endl;
	}

	return 0;
}

