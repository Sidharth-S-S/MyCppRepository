#include <iostream>
using namespace std;

int main(){
    // & operator : Reference operator to show address of any variable 
    int a = 10 ;
    int * pi = &a ; // pi is a pointer to an integer
    cout << pi << endl ;  // 0x6dfe04
    cout << a << " vs Pointer Val : " << *pi << endl ; // 10 vs Pointer Val : 10
    cout << "Size of Pointer to int is : " << sizeof(pi) << endl ; // Size of Pointer to int is : 8

    char c = 'a';
    char * pc = &c ;
    cout << " Pointer Val of PC = " << pc << endl << " Value is : " << *pc << endl ; // Pointer Val of PC = a Value is : a
    cout << "Size of Pointer to character is : " << sizeof(pc) << endl ; // Size of Pointer to character is : 8

    double d = 2.0 ; 
    double * pd = &d ;
    cout << " Pointer Val of PD = " << pd << " Value is : " << *pd << endl ; // Pointer Val of PD = 0x6dfdf8 Value is : 2  
    cout << "Size of Pointer to double is : " << sizeof(pd) << endl ; // Size of Pointer to double is : 8

    cout << "Pointers are stored in the following address space" << endl ;
    cout << "PI : " << pi << " PC : " << pc << "PD : " << pd << endl ;
    /*
    Pointers are stored in the following address space
    PI : 0x6dfe04 PC : a
    PD : 0x6dfdf8
    */

   // If we initialize a pointer without address 
   // Too much garbage to handle it would be like below 
   int *p ;
   cout << *p << endl; //We are trying to get a value from 1 of the garbage location which is created during compile time by the symbol table 

   // that is why when creating a pointer we can assign a null value so it would try to throw error instead of initializing with garbage
   // int *p = 0 // It would show segmentation fault and we know why . 
   // Pointer Arithmatic // p = p + 1 => integer type so next int // double so next double(+8 Byte) // character ( next char +1 B)

}