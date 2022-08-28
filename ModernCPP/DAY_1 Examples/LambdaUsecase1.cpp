#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
//Class library developer
class CA
{
private:
    int a,b;
public:
    CA(int x=0, int y=0):a(x),b(y){ }    
    void print() const {cout <<"CA-print, a=" << a <<",b=" << b << endl;}
    void operator()(CA &ob)
    {
        cout <<"CA::FUNCTOR CALLED" << endl;
        cout <<"a =" << ob.a <<",b=" << ob.b << endl;
    }
    void fun1()
    {
        cout <<"fun1 called, a= " << a <<",b=" << b << endl;
    }
};


//Class library consumer....

void Print(CA& ob)
{
    cout <<"GLOBAL PRINT CALLED" << endl;
    ob.print();
}

int main()
{
    list<CA> ls1;
    for(int i=1;i<=10;i++)
    {
        ls1.push_back(CA(i,i+10));
    }

    //Approach-1
    list<CA>::iterator itr = ls1.begin();
    while(itr != ls1.end())
    {
        itr->print();
        itr ++;
    }
    cout <<"**********************" << endl;
    //Approach - 2

    for_each(ls1.begin(), ls1.end(), Print);
                                  //, Print(object_from_ls1);
    cout <<"**********************" << endl;                                   
    //Approach-3
    /*
        - FUNCTORS are the only member functions of a class that an STL algorithm can bind to,
          and no other member function.

    */ 

   CA obj1;
   for_each(ls1.begin(),ls1.end(), obj1);
                            //, obj1.operator()(object_from_ls1);
    cout <<"**********************" << endl;  
    //Approach-4 [modern approach]  
    auto print = [](CA& ob)
    {
        ob.print();
    };

    
    auto fun1 = [](CA& ob)
    {
        ob.fun1();
    };

    //Now in modern C++, all STL algorithms have been tweaked to also accept lambda's
    //as their 3rd parameter.

    for_each(ls1.begin(),ls1.end(), print);
    cout <<"------------------------------" << endl;
    for_each(ls1.begin(), ls1.end(), fun1);
    cout <<"-----------------------------" << endl;
    //FUNCTOR IMPLEMENTATION INSIDE A LAMBDA
    
    auto func =[&obj1](CA& ob)
    {
        obj1(ob);
    };
    for_each(ls1.begin(), ls1.end(), func);
    cout <<"-----------------------------" << endl;

    return 0;
}