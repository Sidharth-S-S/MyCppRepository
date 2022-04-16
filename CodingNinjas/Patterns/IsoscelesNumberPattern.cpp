#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// copy-item -Path IsoscelesPattern.cpp -Destination IsoscelesNumberPattern.cpp   
	// The Code snippets in Powershell to copy files
	/*
	 Code : Triangle of Numbers
		Input format : 	Integer N (Total no. of rows)
		Output format :	Pattern in N lines
		Constraints :  0 <= N <= 50
		Sample Input 1:  5
		Sample Output 1:

				 1
				232
			   34543
			  4567654
		     567898765
	*/

	int i = 1;
    
	while (i <= n) {
		int spaces = 1;
		while (spaces <= n - i) {
			cout << ' ';
			spaces = spaces + 1;
		}
		// Print the numbers
		int j = 1 , val = i ;
		while (j <= i) {
			cout << val ;
			val++;
			j++;
		}

        val -= 2; // value should be the max which was shown -1 but due to the increment we are subtracting 2 .
		int k = 1; // loop for 2nd number
		while (k < i) {
			cout << val;
            val--;
            k++ ;
		}

		// end of the line in the i th row.
		cout << endl;
		i = i + 1;
	}
}
