#include<iostream>
using namespace std;

//Example on conversion function - overloading 'bool' type for PIMPL model class

class MemManager
{
private:
    int* p;
public:
    MemManager():p(nullptr){ }
    MemManager(int* q):p(q) { }

    void print()
    {
        cout <<"The value pointed to by p = " << *p << endl;
    }   

    ~MemManager() 
    {
        if(p != nullptr)
            delete p;
    }

    //conversion function
    operator bool()
    {
        if(p != nullptr)
            return true;
        else   
            return false;
    }
};

//*************consumer code ****************
int main()
{
    MemManager m1;
    MemManager m2(new int(100));

    if(m1)        //if(m1.operator bool())
        m1.print();
    else
        cout <<"m1 handle is invalid" << endl;
    if(m2)        
        m2.print();
    else    
        cout <<"m2 handle is invalid" << endl;
    return 0;
}