#include<iostream>
using namespace std;

class CA
{

public:
//for this class all 3 methods will be compiler generated and under public
    CA()=default;
    CA(const CA& x)=default;
    CA& operator =(const CA& x) = default;
};

class CB
{

//for this class 2 methods will be compiler generated and under public
//one method generated by the compiler under private

private:
    CB(const CB& x)=default;

public:
    CB()=default;
   
    CB& operator =(const CB& x) = default;
};


//***consumer code************
int main()
{
    CA obj1;
    CA obj2(obj1);
    CA obj3;
    obj3 = obj1;
    cout <<"---------------------" << endl;
    CB obj4;
    // CB obj5(obj4);  //should flag error // this is defined in the private member variables of the class CB
    CA obj5;
    obj5 = obj3;
    return 0;
}