int multiplyNumbers(int m, int n) {
    // Write your code here
    // Base Case // if the n == 0 then return 0 
    if (n==0) return 0 ;
    
    // Recursion
    int TempMul = multiplyNumbers(m,--n) ;
    
    // Small Calculation // Assume that the TempMul has already given correct o/p for n-1 times 
    return TempMul + m ;

}
