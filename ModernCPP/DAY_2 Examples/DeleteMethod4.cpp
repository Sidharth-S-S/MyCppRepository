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

    //operator int() =delete;
    //operator float() = delete;

    template<typename T> operator T() = delete;
    //Attempt similarly for pointer types...
    //..
};

//*************consumer code ****************
int main()
{
    MemManager m1;
    MemManager m2(new int(100));

    int x = (int) m1;
    float y =(float)m2;


    return 0;
}