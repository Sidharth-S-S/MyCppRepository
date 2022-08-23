#include<iostream>
using namespace std;
/* In class initializers, applicable only for non-static data members of the class  */
class CA
{
private:
    int a{};
    int b{ 20 };
    float c = 12.34f;
    int sum = a + b;
    double val = compute();
public:
    /*
        - We don't intend to define our own default constructor, rather
          we want the compiler to assume a default constructor.
    */
    CA() = default;  
   
                      //    [ assumed by the compiler ]
    CA(int z):a(z)  /* ,b(20),c(12.34f),sum(a+b), val(compute())  */
    {
        cout <<"CA one arg. constructor.." << endl;
    }
    double compute()
    {
        return c * 45.56;
    }
    void print()
    {
        cout << "a =" << a << endl;
        cout << "b =" << b << endl;
        cout << "c =" << c << endl;
        cout << "sum =" << sum << endl;
        cout << "val =" << val << endl;
    }
};
//------------------
int main()
{
    CA obj1;
    obj1.print();
    CA obj2(100);
    obj2.print();
    return 0;
}