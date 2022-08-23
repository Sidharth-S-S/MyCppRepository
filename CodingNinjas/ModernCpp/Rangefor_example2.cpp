#include<iostream>
using namespace std;

class CArray
{
private:
            //using both in-class initializer class feature along with brace initialization syntax
    int a[10] = {10,20,30,40,50,60,70,80,90,100};
public:
    void print()
    {
        for(auto x:a)
        {
            cout << x <<",";
        }
        cout << endl;
    }

    /*
      Try and make our 'CArray' type instances are range-for construct
      compatible on the consumer end.
    */

    int* begin()
    {
        return a;
    }
 
    int* end()
    {
        return &a[10];
    }
   
};


//***consumer code************
int main()
{
    CArray obj1;
    //obj1.print();

   for(auto x: obj1) // it needs begin and end function to work .. so define them now  
   {
       cout << x <<",";
   }

    return 0;
}