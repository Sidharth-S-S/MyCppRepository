#include<iostream>
using namespace std;
/*
    - A class having a function pointer as its data member is also known as FUNCTION CLASS.
    - An object of FUNCTION CLASS is also knows as FUNCTION OBJECT

    - For a FUNCTION CLASS it is a good idea to overload the FUNCTION OPERATOR, in short known as
      FUNCTOR.
*/
class Func
{
private:
    void(*fp)();
public:
    Func(void(*ff)()):fp(ff)
    { }

    void Set(void(*ff)())
    {
        fp = ff;
    }

    void Invoke()
    {
        (*fp)();
    }

    void operator()()    //FUNCTOR
    {
        (*fp)();
    }
};


//****class consumer************
void fun1() {cout <<"fun1 called" << endl;}

void fun2() {cout <<"fun2 called" << endl;}


int main()
{
    Func obj1(&fun1);
    //obj1.Invoke();
    obj1();             // obj1.operator()();
    cout <<"*******************" << endl;
    obj1.Set(&fun2);
    //obj1.Invoke();
    obj1();           // obj1.operator()();
    return 0;
}
