#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	// copy-item -Path IsoscelesPattern.cpp -Destination IsoscelesNumberPattern.cpp   
	// The Code snippets in Powershell to copy files
	/*
	  Code : Diamond of stars

    Constraints :  1 <= N <= 49
    Sample Input 1: 5
    Sample Output 1: 
            *
           ***
          *****
           ***
            *
	*/
    int part2 = n / 2;
    int part1 = n - part2;
    int i , star , space ;

    if (n % 2 != 0 && n <= 49)
    {
        i = 1;
        while (i <= part1)
        {
            //print spaces until part1-i
            space = 1 ;
            while (space <= part1 - i ) {
                cout << " " ;
                space++;
            }
            // print stars ith row : 2i -1 no of stars
            star = 1 ;
            while (star < 2*i) {
                cout << "*";
                star++ ;
            }
            cout << endl;
            i = i + 1;
        }

        // print the 2nd instance 
        i = 0;
        while (i < part2)
        {
            //print spaces until i
            space = 0 ;
            while (space <= i ) {
                cout << " " ;
                space++;
            }
            // print stars ith row : 2i -1 no of stars
            star = 1 ;
            while (star < 2*(part2-i)) {
                cout << "*";
                star++ ;
            }
            cout << endl;
            i = i + 1;
        }
    }
}
