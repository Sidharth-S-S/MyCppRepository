#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    /*
    Print the following pattern
    Pattern for N = 4
         *
        ***
       *****
      *******
     *********
    */
    int i = 1 , n = 0;
    cin >> n ;
    
    while (n <=50 && i <= n ){
        int j = 1 , k = 1;
        // Print Spaces
        while (k <= n-i){
            cout << " ";
            k++;
        }
        //Print the Number that starts from i and goes till ith Term ( now print * but odd number of times
        while (j < (2*i)) {
            cout << "*" ;
            j++ ;
        }
        // Increase i till n after the end of the line
        cout << endl ;
        i ++ ;
    }
  
}