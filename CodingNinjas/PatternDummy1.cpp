#include <iostream>
#include <cmath>
using namespace std; 

int main() {
   // pattern has n rows , in the ith Row , space is there then the numbers , ith row => n-i spaces numbers j = i -> i (2*i-1 times)
    /*
    5
1234554321
1234**4321
123****321
12******21
1********1
    */
    int n;
    cin >> n;

    for (int i = n;i>=1;i--){
        for (int j=1;j<=i;j++){
            cout<<j;
        }
        //print the stars ith row n-i-1 times stars
        for (int j=1;j <= 2*(n-i);j++){
            cout<<'*';
        }
        for (int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}