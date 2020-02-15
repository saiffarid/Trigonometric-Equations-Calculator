#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
int operation; //This is the variable to store the number of the trig. function the user choose
double constant;
double lower_boundary;
double upper_boundary;
double a; //This variable is for holding the converted degrees to radians

//This is the function for getting the information needed to start giving out the possible theta values
void get_info(){
        std::cout<<"Insert the value of the constant: ";
        std::cin>>constant;
        std::cout<<"Insert the value of the lower boundary in degrees\n( this is from where you will start getting possible values of theta ): ";
        std::cin>>lower_boundary;
        std::cout<<"Insert the value of the upper boundary in degrees: ";
        std::cin>>upper_boundary;
        std::cout<<"\nHere are your possible values for theta :\n";
}

void decide (){
    std::cout<<"\nInsert the number of the trigonometric function you want:\n";
    std::cout<<"1. Sin()\n";
    std::cout<<"2. Cos()\n";
    std::cout<<"3. Tan()\n";
    std::cin>>operation;
    
    if (operation==1){
        get_info();
        for (double i = lower_boundary; i<=upper_boundary; i++)
        {   a = i*(M_PI/180);
            if ((sin(a)-constant)<0){if ((-1*(sin(a)-constant))<0.00000001){std::cout<<i<<"\n";}}
            else {if ((sin(a)-constant)<0.00000001){std::cout<<i<<"\n";}}
    }}

    else if (operation==2){
        get_info();
        for (double i = lower_boundary; i<=upper_boundary; i++)
        {   a = i*(M_PI/180);
            if ((cos(a)-constant)<0){if ((-1*(cos(a)-constant))<0.00000001){std::cout<<i<<"\n";}}
            else {if ((cos(a)-constant)<0.00000001){std::cout<<i<<"\n";}}
            }
    }

    else if (operation==3){
        get_info();
        for (double i = lower_boundary; i<=upper_boundary; i++)
        {   a = i*(M_PI/180);
            if ((tan(a)-constant)<0){if ((-1*(tan(a)-constant))<0.00000001){std::cout<<i<<"\n";}}
            else {if ((tan(a)-constant)<0.00000001){std::cout<<i<<"\n";}}
            }
    }

    else {std::cout<<"INVALID INPUT ! Please enter the number of an existing operation.\n";}
}

int main() {
    std::cout<<"This program was coded by Saifeldin Mohamed Farid from 11XE in 2020\n";
    std::cout<<"-------------------------------------------------------------------\n";
    std::cout<<"TRIGONOMETRIC EQUATIONS CALCULATOR\n";
    std::cout<<"-------------------------------------------------------------------\n\n";
    while (true){decide();}
}