#include<iostream>
using namespace std;


int main(){

    /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int i = 1, n = 0,val = 1 ;
    cin >> n ; 

    while (i <= n) {
        int j = 1;
        while (j <= i) {
            cout << val;
            j++;
            val++;
        } 
        cout << endl;
        i++ ;
    }
}