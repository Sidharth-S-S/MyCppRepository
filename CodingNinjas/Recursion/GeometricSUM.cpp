#include <cmath>

double geometricSum(int k) {
    // Write your code here
    //Base Case , if the k == 0 then 1/2^0 = 1 
    if (k==0) return 1 ;
    
    //Recursion assuming till k-1 everything is done till then 
    double GeomSum = geometricSum(k-1) ;
    
    // Small Calculation 
    return GeomSum + 1 / pow(2,k);

}