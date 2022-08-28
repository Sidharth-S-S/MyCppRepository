#include<iostream>
#include<memory>
using namespace std;
class CB;
class CA
{
private:
	int a{10}, b{20};
public:
	CA() = default;
	CA(int x, int y) :a(x), b(y) { }
	CA(const CA& x) :a(x.a), b(x.b) { cout << "CA copy constr..." << endl; }
	
	~CA() { cout << "CA destructor..." << endl; }
	void print_data()
	{
		cout << "CA print_data..." << endl;
		cout << "a:" << this->a << ",b:" << this->b << endl;
	}
	
	friend CB;
};

class CB
{
private:
	unique_ptr<CA> ptr{ make_unique<CA>() };
public:
	CB() = default;
	CB(int x, int y) :ptr{ make_unique<CA>(x,y) } {}
	void print_data1()   //wrapper to CA print_data() 
	{
		cout << "CB print_data..." << endl;
		ptr->print_data();
	}

	void print_data2()  //directly access enclosed instances data...
	{
		const auto& [i, j] = *ptr;
		cout << "CA object data:" << i << "," << j << endl;
	}
};

//*****consumer code *****
int main()
{
	CB obj1;
	//obj1.print_data1();
	obj1.print_data2();
	cout << "main terminates..." << endl;
	return 0;
}