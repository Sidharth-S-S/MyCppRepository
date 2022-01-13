#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n ;
    cin >> n ;
    
    for (int i=1;i<=n;i++) {
        // print the spaces 1st ; in ith row i-1 spaces to print
        for (int j = 1 ; j<=n-i;j++) {
            cout << " " ;
        }
        // Now print the star . As stars can be printed at a go hence we have to print ith row : 2i -1 no of stars
        for (int k = 1; k <= 2*i-1 ; k++) {
            cout << "*" ;
        }
        cout << endl;
    }
}