int sumOfDigits(int n) {
    // Write your code here
    // Base Case
    if (n < 10) return n;
    
    // Recursion Case
    int TempSum = sumOfDigits(n/10) ;
    
    // Simple Calculation
    return TempSum + (n%10) ;

}