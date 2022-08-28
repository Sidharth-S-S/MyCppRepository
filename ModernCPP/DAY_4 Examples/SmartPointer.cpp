#include<iostream>
using namespace std;

class CA
{
private:
    int a;
public:
    CA(int x=0):a(x){cout <<"CA constructor" << endl;}   
    ~CA(){cout <<"CA destructor" << endl;} 
    void result(){cout <<"CA-result, a =" << a << endl;}
};


class CB
{
private:
    int b;
public:
    CB(int x=0):b(x){cout <<"CB constructor" << endl;}   
    ~CB(){cout <<"CB destructor" << endl;} 
    void output(){cout <<"CB-output, b =" << b << endl;}
};

/*
    We plan to provide an additional wrapper class, that helps managing instances of 
    any of the above types easily. Broadly trying to ensure there is no memory leak or
    dangling-pointer.
*/

template<typename T> class Smartpointer  //class is a MOVE-ONLY TYPE
{
private:
    T* p;   //PIMPL
public:
    Smartpointer():p(nullptr){ }
    Smartpointer(T* x):p(x){ }
    ~Smartpointer()
    {
        if(p)
            delete p;
    }

    void Release()
    {
        if(p)
            delete p;
    }
    Smartpointer(const Smartpointer& x) = delete;
    Smartpointer& operator =(const Smartpointer& x)=delete;

    Smartpointer(Smartpointer&& x):p(x.p)
    {
        x.p = nullptr;
        delete x.p;
    }
    Smartpointer& operator =(Smartpointer&& x)
    {
        this->p = x.p;
        x.p = nullptr;
        delete x.p;
        return *this;
    }    

    operator bool()
    {
        if(p)
            return true;
        else    
            return false;
    }

    T* operator ->()
    {
        cout <<"Smartpointer operator ->() called" << endl;
        return p;
    }

    T& operator*()
    {
        cout <<"Smartpointer operator *() called" << endl;
        return *p;
    }

};

//***********consumer code ****************
int main()
{
    /*
        Instances s1, s2, s3 though they are not pointers, yet they are capable
        of behaving and acting like pointers - i.e. the smartness.

        This is made possible by overloading the following operators in a PIMPL model class
        -   ->  arrow
        -   *  star 
    */
    Smartpointer<CB> s1(new CB);
    s1->output();     // (s1.operator ->())->output();

    Smartpointer<CA> s2(new CA);
    s2->result();

    Smartpointer<CA> s3(new CA(200));
    (*s3).result();


    //Smartpointer<CA> s4(s3);
    Smartpointer<CA> s4(std::move(s3)); 
    
    return 0;
}