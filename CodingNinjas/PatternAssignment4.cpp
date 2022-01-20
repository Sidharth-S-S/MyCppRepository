#include<iostream>
using namespace std;

int main() {
	/*
    Print the following pattern for the given N number of rows.
    Pattern for N = 4

    4444
    4444
    4444
    4444

    Input format :      Integer N (Total no. of rows)
    Output format :     Pattern in N lines
    */
	int n ,i = 1;
    cin >> n ;

    while (i <= n) {
        int j = 1 ;
        while (j <= n) {
            cout << n ;
            j++;
        }
        cout << endl;
        i++ ;
    }
 
}