#include "iostream"
#include "cmath"

class Fraction{
    private:

    int Numerator;
    int Denominator;

    void simplify(){
        int gcd = 1;
        gcd = std::min(Numerator,Denominator);
        for (int i = gcd ; i >= 1  ; i--){
            if ((Numerator % i == 0) && (Denominator % i == 0)){
                gcd = i;
                break;
            }
        }
        this->Numerator = Numerator / gcd;
        this->Denominator = Denominator / gcd ; 
    }

    public:

    // always create a class if the Numerator and Denominator both are available
    // Constructor with 2 parameters is the solution as it over ride the default constructor function
    Fraction(int Numerator, int Denominator){
        std::cout << "Fraction Constructor is called with Parameters." << std::endl;
        this->Numerator = Numerator;
        this->Denominator = Denominator;
    }

    // Values to Numerator and Denominator are added already
    void Print(){
        std::cout << Numerator << " / " << Denominator ;
    }

    void Add(const Fraction &f) {
        // There is a reason why the input parameter is not just Fraction f2. 
        // We could easily perform the operation using fraction f , but inside the main there would be an object that internally copies to this Fraction object f. 
        // To avoid the copy we can use the same memory of Object and there is no need of copying
        // Why Const ??   constant does not allow modification to the object which is created from the main() function
        
        // a/b + c/d =>   a*d + c*b / b*d   and then simplify
        this->Numerator = this->Numerator * f.Denominator + f.Numerator * this-> Denominator ; 
        this->Denominator = this->Denominator * f.Denominator ;
        simplify() ; // simplify the current object
    }

    void Multiply(const Fraction &f){
        // Again constand object is created not allow the modification and & is used to avoid copy
        this->Numerator = this->Numerator * f.Numerator ;
        this->Denominator = this->Denominator * f.Denominator ;
        simplify() ;
    }

} ;

int main (){

    Fraction f1(10,2); // there is no default constructor hence only parameterized constructors exists
    int choice ;
    std::cin >> choice;
    Fraction f2(2,4);

    switch(choice) {
        case 1: // Add 2 fractions
            f1.Print() ;
            std::cout << " + " ;
            f2.Print() ;
            f1.Add(f2) ; // There must be a Add method that will add the 2 fractions and save the result to f1
            std::cout << " = " ;
            f1.Print() ;
            break;
        case 2: //multiply 2 fractions
            f1.Print() ;
            std::cout << " * " ;
            f2.Print() ;
            f1.Multiply(f2) ; // There must be a Multiply method that will * the 2 fractions and save the result to f1
            std::cout << " = " ;
            f1.Print() ;
            break;
        default:
            break ;
    }

    return 0;
}