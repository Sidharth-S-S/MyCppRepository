#include <iostream>
using namespace std;

#include <cstring>

/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :

1) Only one disk can be moved at a time.
2) A disk can be moved only if it is on the top of a rod.
3) No disk can be placed on the top of a smaller disk.

Print the steps required to move n disks from source rod to destination rod.
Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.

Input Format :   Integer n
Output Format :  Steps in different lines (in one line print source and destination rod name separated by space)
Constraints :    0 <= n <= 20

Sample Input 1 :  2
Sample Output 1 : 
a b
a c
b c
Sample Input 2 : 3
Sample Output 2 :
a c
a b
c b
a c
b a
b c
a c
*/

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here
    // Base case 
    // When there is no DIsc or 1 disc then just move from Src to Dest
    const char MyStr[] = "Moved From " ;
    if ( n == 0 ) return ;
    if (n==1) {
        cout << MyStr << source << " " << destination << endl;
        return ;
    }

    // Recursion , now assume how the logic works here 
    // Move n-1 from Src => Aux assuming Dest as the helper 
    towerOfHanoi(n-1, source, destination, auxiliary) ;

    // Simple Calculation 
    // Move the nth Tower now from Source to Destination
    cout << MyStr << source << " " << destination << endl;

    // Again you have to do a recursion this time from 
    // Aux => Dest  assuming Src as helper
    towerOfHanoi(n-1, auxiliary, source, destination) ;
}

int main() {
    int n ; 
    cin >> n ;
    towerOfHanoi(n, 'a' , 'b' , 'c') ;
}