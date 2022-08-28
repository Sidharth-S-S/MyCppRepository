#include<iostream>
#include<thread>
using namespace std;

void fun()
{
    cout <<"fun called, its id:"<< this_thread::get_id() << endl;
}

int main()   //PARENT THREAD
{
    cout <<"Parent thread main execution started..., its id:" << this_thread::get_id() << endl;
    //create a child thread whose unit of work shall be 'fun()'
    thread th1(&fun);
    
    //....
    //...
    //th1.detach();  
    cout <<"Parent thread main execution completed..."<< endl;

    if(th1.joinable())
            th1.join();
    return 0;
}