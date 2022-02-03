#include <iostream>
#include <cmath>
#include <limits>       // std::numeric_limits
using namespace std; 

//Print the Celcius to Farenheit Table Directly from the function
double Far2Cel(double F){
    return (5*(F-32)/9) ;
}
void printTable(double start, double end, double step) {
    for (double i = start;i <= end;i+=step){
        cout << i << ' ' << Far2Cel(i) <<endl;
    }
}

int main() {
    cout << "Enter Start End and Step Values in Farhenheit ." << endl ;
    double Start,End,Step;
    cin >> Start >> End >> Step;
    printTable(Start,End,Step) ;
}