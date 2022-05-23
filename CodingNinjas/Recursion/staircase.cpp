#include "MyHeaderFiles.h"

int staircase(int n){
    /*
    A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
    Implement a method to count how many possible ways the child can run up to the stairs. 
    You need to return number of possible ways W.

    Concept : Assume you are using recursion case for n = 5 steps .
            the child can run 1 step then assume that 4 steps are done by recursion => 1 will be small calculation
            when child take 2 step then recrsion will handle 3 steps ; 3 + recursion will handle 2 
            when n = 0 then the default is 1 way ;;; exception handling          
    */
    // basic cases
    // recursive cases with n-1 + 1 ; n-2 + 2 ; n-3 + 3 steps
    
    if ( n >= 3) {
        return (staircase(n-1) + staircase(n-2) + staircase(n-3)) ;
    } else if ( n == 2) {
        return (staircase(n-1) + staircase(n-2)) ;
    } else if ( n == 1) {
        return staircase(n-1);
    } else { 
        return 1;
    }
}