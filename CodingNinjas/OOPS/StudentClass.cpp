#include <iostream>

class Student {
    private:

    int Age ; // defalt initializing is Private
    
    public :

    
    int RollNumber ; // Public can be accessed by class methods and outside objects as well 

    // Constructer default is always called while initializing the Object.
    // If it is created by User then it will override the system default constructor.

    // Default constructor
    Student() {
        std::cout << "Constructer1 is called !!" << std::endl;
    }

    // Parameterized Constructer is called 
    Student(int r) {
        std::cout << "Constructer2 is called !!" << std::endl;
        RollNumber = r ; // It is also another type of constrcter but it should be different from the previous Constructer and different from the default constructor 
    }


    // need of getter and setter is that 
    // if there is a limit to Age or lets say only people with Passwords can edit the field then instead of Private we can declare it as a Public property 

    void setAge(int tempAge) { 
        if (tempAge > 30) {
            return;
        }
        Age = tempAge; // Getter fn will be used  
    }

    int getAge() {
        return Age;
    }

    void display(){
        std::cout << "The Candidate Age is : " << Age << " & RollNumber : " << RollNumber << std::endl;
    }

    void EditRollNumber(int tempRollNumber,int Password) {
        if (Password !=  34512 ){
            std::cout << "Alert!! Wrong Password !! Entered PW : " << Password << " .Please Try Again !!!" << std::endl ;
            return ;
        }
        RollNumber = tempRollNumber;
    }
} ;