#include "iostream"

class Student{
    int RollNumber;
    int Age;
    
    public:

    // Default constructor is called automatically but if defined in the class , it will override
    Student() {
        std::cout << "Default constructor is called !!!" << std::endl;
    }

    

    // Parameterized Constructor with 2 arguments
    Student(int TempRollNumber, int TempAge){
        std::cout << "Parameterized constructor2 is called !!!" << std::endl;
        RollNumber = TempRollNumber;
        Age = TempAge;
    }

    // When the Argument name and the Property name are same then how to segreate them ??? 
    // " use this pointer"  this pointer is by default the dynamic pointer to the objects
    // Parameterized Constructer with 1 argument
    Student(int Age){
        std::cout << "Parameterized constructor1 is called !!!" << std::endl;
        this->Age = Age; // as both the name are same , it causes confusion .
    }


    // Print the Parameters
    void Print(){
        std::cout << "Student Roll Number: " << RollNumber << " Age: " << Age << std::endl;
    }

    // Edit the roll number with a constraint
    void EditRollNumber(int TempRollNumber){
        if (RollNumber != TempRollNumber) {
            RollNumber = TempRollNumber;
            std::cout << "Roll Number is changed!!!" << std::endl;
        }
    }

    // Destructor is called at the end of the scope of the object of the class while the variable is going out of scope.
    ~Student(){
        std::cout << "Destructor is called !" << std::endl ;
    }

} ;