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
       LVALUE PAIR DIS-ABLED
    */
    CA(const CA& x) =delete;
   
    CA& operator =(const CA& x)=delete;

    /*
        RVALUE PAIR:
            - It is a WRITE on both source as well as target element 
            - i.e. the formal parameters should not be 'const'
    */

   CA(CA&& x)
    {
        cout <<"CA RVALUE copy constructor called" << endl;
    }
   CA& operator =(CA&& x)
    {
        cout <<"CA RVALUE assignment function called" << endl;
        return *this;
    }
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