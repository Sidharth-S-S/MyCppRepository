int countZeros(int n) {
    // Write your code here
    // Base Case   if the number is less than 10 then 1 digit and always check whether return is 1 or 0 
    if ( n < 10 ) {
        if (n == 0) return 1 ;
        else return 0 ;
    }
    
    //Recursion Case
    int TempCount = countZeros(n/10) ;
    
    // Small Calculation
    if ( n%10 == 0 ) return TempCount + 1 ; 
    else return TempCount ;
}