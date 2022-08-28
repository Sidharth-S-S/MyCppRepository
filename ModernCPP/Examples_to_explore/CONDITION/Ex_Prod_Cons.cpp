#include<iostream>
#include<queue>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

std::mutex mx;
std::queue<int> values;
bool done = false;
condition_variable cVar;

void Consumer()
{
    unique_lock<mutex> lock(mx);
    while (!done)
    {
        cVar.wait(lock);
    }
    while (!values.empty())
    {
        cout << values.front() <<",";
        values.pop();
    }
}

void Producer()
{
    for (int i = 1; i <= 500; i++)
    {
        values.push(i);
    }
    done = true;
    cVar.notify_one();
}

//****************
int main()
{
    thread th1(&Consumer);
    thread th2(&Producer);

    th1.join();
    th2.join();
    return 0;
}