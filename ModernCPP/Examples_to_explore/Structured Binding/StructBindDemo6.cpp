#include<iostream>
#include<tuple>
#include<map>
using namespace std;

struct MyStruct
{
    pair<string,string> p1 ={"- C++17 -","- standard -"};
    pair<string,string> p2 ={"- structured -","- binding -"};

    auto BindFunc()
    {
        return make_tuple(p1.first,p1.second, p2.first,p2.second);
    }
};

int main()
{
    pair<int,float> pobj1(10,34.12f);
    auto[x1,x2] = pobj1;
    cout << x1 <<"," << x2 << endl;
    cout <<"-----------------------" << endl;
    auto[y1,y2] = MyStruct();
    
    cout << y1.first <<"," << y1.second << endl;
    cout << y2.first <<"," << y2.second << endl;
    cout <<"-----------------------" << endl;
    MyStruct ob1;
    auto[s1,s2,s3,s4] = ob1.BindFunc();
    cout << s1 <<"," << s2 << endl;
    cout << s2 <<"," << s3 << endl;
    cout <<"-----------------------" << endl;
    
    return 0;
}