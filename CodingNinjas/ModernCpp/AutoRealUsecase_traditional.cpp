#include<iostream>
using namespace std;
//Traditional C++ generic code

//GENERIC CODE AUTHOR...
// if we add another typename to the T3 now then it would be error , 
// because we can not now progress as  T3 is not a part of the formal parameter list for the function definition

//template<typename T1, typename T2, typename T3> T3 Add(T1 x, T2 y)   
template<typename T1, typename T2, typename T3> T1 Add(T2 x, T3 y)    // modern solution demands the name to be consistently used , T1 , T2 then T3 ,, can not use whereever we want . 
{
    return x+y;
}

// Issue :: T3 is not a formal parameter but a return type ???   now the consumer must change the type 

//NewTemplate change :: 
// if the names are consitent then the consumer just needs to modify the 1 parameter T1 ; 

//GENERIC CODE CONSUMER
int main()
{
    float x;
    //x = Add(23.21f, 100); // 123.21 as output 1st is float , 2nd is integer ;  now the function template will be like ::    float Add (float x , int y ) { return x+y } 
    //x = Add<float,int,float>(23.21f, 100); // Explicit Instanciation  here as implicit is failed due to the T3 
    x = Add<float>(23.21f, 100);  // New template return is T1 hence jst 1 defination is fine 
    cout <<"x = " << x << endl;
    cout <<"***********" << endl;
    //x = Add(100, 23.21f); // 123 as output  // now T1 : int , T2 : float ;                                                  int Add (int x , float y) { return x+y; } 
    //x = Add<int,float,float>(100, 23.21f); // 123 as output  // now T1 : int , T2 : float ;
    x = Add<float>(100, 23.21f);
    cout <<"x = " << x << endl;
    // the problem is due to T1 and T2 being the return type and hence for 1 it is int and other it is float . 
    return 0;
}