#include <iostream>
using namespace std;

int main(){
    int Arr[10] = {0,1,2,3,4,5,6} ;
    int * p = &Arr[0];

    cout << Arr << endl;  // 0x6dfdf0
    cout << p << endl;  // 0x6dfdf0
    cout << *Arr << endl; // 0
    cout << *p << endl; // 0
    cout << p + 1 << endl; // 0x6dfdf4 // Here Pointer is increased in 4 byte to point to the next element of the array // hence not 8Byte increase
    cout << *(p+1) << endl; // 1 
    cout << &Arr << endl;  // 0x6dfdf0
    cout << &p << endl; // 0x6dfde8  // This is completely another location that has nothing to do with the array address

    // Change Pointer reference 
    p = p + 3 ;
    cout << p << " : " << *p << endl; // 0x6dfdfc : 3

    // Arr = Arr + 1 //  This expression is not possible at all due to the already created Array reference 
    // Array can not reference to another location . 

    cout << sizeof(Arr) << endl; // 40 bytes
    cout << sizeof(p) << endl; // 8 bytes  // Pointer automatically created hence 8 but array is 4 .

    // Important Point is how to reference array to pointer 
    int * b = Arr ;
    cout << Arr[2] << " Vs "<< b[2] << endl; //Both are same and this is how Array is passed to function 

}