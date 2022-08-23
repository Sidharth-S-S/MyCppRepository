#include "iostream"
using namespace std;

#include "StudentClass.cpp"

int main(int argc, char** argv){
    Student s1,s2;
    Student *s3 = new Student();
    
    s1.RollNumber = 100 ;
    s2.RollNumber = 103 ;
    s3->RollNumber = 104 ; // Pointer will use -> or   (* s3).RollNumber 

    s1.display() ;  // garbage ++ 100
    s2.display() ;
    s3->display() ;  // Here also the call is with a dereference  and then access the method
    
    // Now the age is a Private Variable. Before even trying to change anything , we need to use the getter and setter now .
    // cout << s1.age << endl   => Error as Age is not accessible  & hence getter is used as display method

    s1.setAge(21) ;
    s2.setAge(32) ; // it wont change the value due to the condition 
    s3->setAge(28) ;

    s1.display() ;
    s2.display() ;
    s3->display() ; 

    s3->EditRollNumber(109,12345) ; // edit the Roll Number with a PW
    
    return 0 ;
}