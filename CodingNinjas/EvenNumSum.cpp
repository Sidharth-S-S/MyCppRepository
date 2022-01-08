#include<iostream>
#include<cmath>
using namespace std;

int main() {
    // Given a number N, print sum of all even numbers from 1 to N.
    int n , sum = 0 , temp = 0 ;
    cin >> n ;

    while (n >= temp++) {
        cout << temp << endl;
        if ( temp % 2 == 0) {
            sum += temp;
        }
    }
    cout << sum << endl ;
}