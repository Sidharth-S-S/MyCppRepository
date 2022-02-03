#include <iostream>
#include <cmath>
#include <limits>       // std::numeric_limits
using namespace std;

int main(){
    int a[100] , n , max = numeric_limits<int>::min() ;
    cout << "Please Enter the total number of elements" << endl;
    cin >> n ;

    for (int i=0;i<n;i++) {
        cout << "Please Enter Element Number : " << i << " : ";
        cin >> a[i];
        if (a[i] > max) {
            max = a[i] ;
        }
    }

    cout << "Max Number in the Array is : " << max << endl ;

}