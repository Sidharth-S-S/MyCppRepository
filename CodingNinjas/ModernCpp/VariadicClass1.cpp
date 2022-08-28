#include<iostream>
using namespace std;

//BASE CLASS
template<typename... PARAMETER_PACK> class CA  
{
public:
    CA(){cout <<"Base class CA" << endl;}
};

//DERIVED CLASS CUM SPECIALIZED CLASS
template <typename PARAMETER_TYPE, typename ... PARAMETER_PACK>
           class CA <PARAMETER_TYPE, PARAMETER_PACK...> : private CA <PARAMETER_PACK...>
{
private:
    PARAMETER_TYPE data;
public:
    CA(PARAMETER_TYPE h, PARAMETER_PACK... args) :CA<PARAMETER_PACK... >(args...), data(h)
    {
        cout << "No. of elements left further ..." << sizeof...(args) << endl;
        cout << "data " << data << endl;
    }
};


//***************************
int main()
{
    CA<int, float, double> obj1(10,12.34f, 56.12);
    //CA<int, float, int, char> obj1(10, 12.34f, 56, 'c');
    return 0;
}

/*----------------------------------------------------------------
Base class CA
No. of elements left further ...0
data 56.12
No. of elements left further ...1
data 12.34
No. of elements left further ...2
data 10

CA<int, float, double> obj1(10,12.34f, 56.12);

1st type is int -> class CA<int>:private CA<float, double> {
    private:
    int data ; // 10
    public:
    CA(int h,[12.34f,56.12]) //ctr : CA<float, double>([12.34f, 56.12]),data(h) //remaining call to base class
    {
        ... 
    }
}

class CA<float> : private CA<double>
{
    float data ; 
    public :
    CA(float h,[56.12]) // ctr : CA<double> ([56.12]) , data(h)
}

class CA<double> : private CA<>
{
    double data ;
    public :
    CA(double h) 
}

so it is a recursion and once int , float , double => float,double => double => base class CA
print is in reverse order hence . 

*/