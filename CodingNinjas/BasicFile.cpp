#include<iostream>
using namespace std;

int main() {
	/*
    Write a program to calculate the total salary of a person. The user has to enter the basic salary (an integer) and the grade (an uppercase character), and depending upon which the total salary is calculated as -
    totalSalary = basic + hra + da + allow – pf

    where :
    hra   = 20% of basic
    da    = 50% of basic
    allow = 1700 if grade = ‘A’
    allow = 1500 if grade = ‘B’
    allow = 1300 if grade = ‘C' or any other character
    pf    = 11% of basic.
    Round off the total salary and then print the integral part only.
    Note: Try finding out a function on the internet to do so
    */
	int basic ;
    float Total_Salary = 0 ,allow =0;
    char grade ;
    cin >> basic >> grade ; 

    switch (grade)
    {
        case 'A':
            allow = 1700;
            break;
        case 'B':
            allow = 1500;
            break;
        case 'C':
            allow = 1300;
            break;    
        default:
            break;
    }

    Total_Salary = float(basic) + 0.20*basic + 0.50*basic + allow - 0.11*basic ;
    if (Total_Salary - int(Total_Salary) < 0.5 ){
        cout << int(Total_Salary) << endl ;
    } else {
        cout << int(Total_Salary)+1 << endl ;
    }   
}