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
    CA obj2(obj1);  // copy constructor
    obj2 = obj1;  // assignment operation
    cout <<"*****************" << endl;
    
    //RVALUE operation
    CA obj4; // named value now not really a RVALUE here 
    //CA obj5(obj4);    // CA LVALUE copy constructor called
    //obj4 = obj5;      //CA LVALUE copy constructor called
    
    // the solution is to use std::move
    CA obj5(std::move(obj4));
    obj4 = std::move(obj5);

    return 0;
}