#include<iostream>
using namespace std;

//A Modern C++ class comprising of both LVALUE and RVALUE pairs of COPY CONSTRUCTOR/ASSIGNMENT FUNCTION

class CA
{
private:
    //..
public:
    CA(){ cout <<"CA default constructor..." << endl;}
    /*
       LVALUE PAIR:
       - It is a READ-ONLY business on the source and a WRITE on the target element
       - i.e. the formal parameters must be qualified as 'const'
    */
    CA(const CA& x)
    {
        cout <<"CA LVALUE copy constructor called" << endl;
    }
    CA& operator =(const CA& x)
    {
        cout <<"CA LVALUE assignment function called" << endl;
        return *this;
    }

    /*
       RVALUE OPERATION DIS-ABLED
    */

   CA(CA&& x) = delete;
    
   CA& operator =(CA&& x)=delete;
};

//********consumer code**************
int main()
{
    CA obj1;
    //LVALUE OPERATION
    CA obj2(obj1);  
    obj2 = obj1;
    cout <<"*****************" << endl;
    //RVALUE operation
    CA obj4;
    CA obj5(std::move(obj4));  //std::move() function converts an LVALUE to an RVALUE type
    obj4 = std::move(obj5);

    return 0;
}