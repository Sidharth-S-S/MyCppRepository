#include <iostream>
#include <cmath>
using namespace std; 

int main() {
    /*
You are given S, a sequence of n integers i.e. S = s1, s2, ..., sn. 
Compute if it is possible to split S into two parts : s1, s2, ..., si and si+1, si+2, ….., sn (0 <= i <= n) in such a way that 
the first part is strictly decreasing while the second is strictly increasing one.

 Note :  We say that x is strictly larger than y when x > y.  So, a strictly increasing sequence can be 1 4 8. However, 1 4 4 is NOT a strictly increasing sequence.

Input format :
    Line 1 : Integer 'n'
    Line 2 and Onwards : 'n' integers on 'n' lines(single integer on each line)

Output Format : "true" or "false" (without quotes)

Constraints :  1 <= n <= 10^7

Sample Input 1 :

5
9
8
4
5
6

Sample Output 1 :   true

    */
   long long int count,num=0;
   cin >> count ;

   int current_num,prev_num,PivotPoint=0;
   bool isInc = false ; 
   
   for (int i = 0; i < count; i++){
       long long int placeval = pow(10,i);
       cin >> current_num ;
       // Save the number in the reverse order so that it can be taken 1 by 1 from beginning by quotient 
       num = num + current_num * placeval ;
    }

    for (int i = 1; i <= count; i++){
        prev_num = current_num;
        current_num = num % 10;
        num = num / 10 ;

         // Set the values and flag correctly for iteration 1 
        if (i == 1 ){
            if ((num % 10) > current_num){
                isInc = true;
            } else {
                isInc = false ;
            }
            PivotPoint ++ ;
            continue;
        }

        // from iteration 2 onwards it will be correct .
        if ((current_num > prev_num) && !(isInc)){
            isInc = true;
            PivotPoint ++ ;
        }else if (isInc && current_num < prev_num){
            isInc = false;
            PivotPoint ++ ;
        } else if (current_num == prev_num){
            PivotPoint = 3 ;
        }
    }
    if (PivotPoint > 2) {
        cout << "false" ;
    } else {
        cout << "true" ;
    }
}