#include<iostream>
using namespace std;

template<typename...Args> auto Compute(Args ...pack)
{
    auto z=100;

    //return z * (pack + ...);     //Unary Right fold  --> z*(Args1 + (... + (ArgsN-1 + ArgsN)))
    
    //return (... + pack);     //Unary Left fold  --> ((Args1 + Args2) + ...) + ArgsN
    
    
    //return (z + ... + pack);   //Binary Left fold --> (((z + Args1) + Args2) + ...) + packN
    return (pack +...+ z);     //Binary Right fold --> Args1 + (... + (ArgsN-1 + (ArgsN + z)))
}

int main()
{

   auto result= Compute(20,49,12.34,5.12f);
   cout <<"result:" << result << endl;
   return 0;
}