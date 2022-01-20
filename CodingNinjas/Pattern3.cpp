#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int i = 1, n = 0,val = 1 ;
    cout << "Enter the Number of Rows for the Pattern" << endl;
    cin >> n ; 

    while (i <= n) {
        int j = 1, k = 1 ;
        // insert space here like for the i th row , we have to insert a space  n - i  times ;
        while (k <= n-i){
            cout << "  ";
            k++ ;
        }
        while (j <= i) {
            cout << val << " ";
            j++;
            val++;
        } 
        cout << endl;
        i++ ;
    }
}