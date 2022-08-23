#include "iostream"
using namespace std;

#include "StudentClass_Ctr_Dtr.cpp"

int main(int argc, char** argv){
    Student s1,s2(15);
    Student *s3 = new Student(18,103);

    s3->Print();

    // Other constructor are Copy constructor
    Student s4(*s3) ;
    s4.Print();
    s4.EditRollNumber(105) ;

    //copy assignment operator
    s1=s4 ;
    s1.Print();
 
    // destructor is called for the STACK VAR
    // for the HEAP variables we have to delete the same by delete keyword.
    delete s3;
    
    return 0 ;
}