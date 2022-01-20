#include <iostream>
#include <cmath>
#include <limits>       // std::numeric_limits
using namespace std; 

int main() {
    /*
Take input a stream of n integer elements, find the second largest element present.
The given elements can contain duplicate elements as well. 
If only 0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).

Input format :
Line 1 : Total number of elements (n)
Line 2 : N elements (separated by space)

Sample Input 1:
 4
 3 9 0 9
Sample Output 1: 3

Sample Input 2 :
 2
 4 4

Sample Output 2:
 -2147483648

Sample Output Explanation:

Since both the elements are equal here, hence second largest element is INT_MIN i.e. ( -2^31 )
*/
    int n ;
    cin>>n ;

    if (n >1) {
        int count = 0,current_num,largest_num = numeric_limits<int>::min(),Sec_largest_num = numeric_limits<int>::min();
        while (count < n){
            count ++ ;
            cin >> current_num ;
            //cout << current_num << endl ;
            if ( current_num > largest_num ) {
                Sec_largest_num = largest_num;
                largest_num = current_num ;
            } else if ((current_num > Sec_largest_num) && (current_num != largest_num)){
                Sec_largest_num = current_num;
            }
        }
        cout << Sec_largest_num;
        // return 0;  exit the code as no need to do anything else 
    }else {
        cout << numeric_limits<int>::min() ;
    }
}