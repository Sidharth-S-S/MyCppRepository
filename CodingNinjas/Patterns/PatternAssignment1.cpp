#include<iostream>
using namespace std;


int main(){

    /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int i = 1, n = 0;
    cin >> n ; 

    while (i <= n) {
        int j = 0;
        while (j < i) {
            cout << j+i;
            j++;
        } 
        cout << endl;
        i++ ;
    }
}