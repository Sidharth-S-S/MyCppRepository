#include<iostream>
using namespace std;


int main(){

    /*
    Print the following pattern
    Pattern for N = 4
         1
        23
       345
      4567
     56789
    */
    int i = 1 , n = 0;
    cin >> n ;
    
    while (i <= n ){
        int j = 0 , k = 1;
        // Print Spaces
        while (k <= n-i){
            cout << " ";
            k++;
        }
        //Print the Number that starts from i and goes till ith Term
        while (j < i) {
            cout << i+j ;
            j++ ;
        }
        // Increase i till n after the end of the line
        cout << endl ;
        i ++ ;
    }

}