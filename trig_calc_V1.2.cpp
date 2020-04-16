#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#define _USE_MATH_DEFINES
double operation; //This is the variable to store the number of the trig. function the user chooses
//Operation is a double to avoid the error that happens when the user enters a floating point negative number
double constant;
double lower_boundary;
double upper_boundary;
std::vector<double> answers_U; //For storing the theta values closer to the upper boundary
std::vector<double> answers_L; //For storing the theta values closer to the lower boundary
int U; //Counter for the how many will be added ( according to the algorithm ) in the direction of the upper boundary
int L; //Counter for the how many will be added ( according to the algorithm ) in the direction of the lower boundary
double result;
//This is the function for getting the information needed to start giving out the possible theta values
void get_info(){
        std::cout<<"Insert the value of the lower boundary in degrees\n( this is from where you will start getting possible values of theta ): ";
        std::cin>>lower_boundary;
        std::cout<<"Insert the value of the upper boundary in degrees: ";
        std::cin>>upper_boundary;
        if (lower_boundary > upper_boundary) {std::cout<<"\nERROR ! The lower boundary cannot be bigger than the upper boundary\n\n"; get_info();}
        if (upper_boundary==lower_boundary){std::cout<<"\nThis range is too narrow.\n";
                                            std::cout<<"Which leads to inaccuracies in calculations.\n";
                                            std::cout<<"Please select a wider range.\n\n";
                                            get_info();}
}
//This is the function for printing out the theta values from their vectors
void print_theta_values(){
    std::cout<<"\nHere are your possible values for theta :\n";
    for (int i = answers_L.size()-1; i>=0; i--){std::cout<<answers_L[i]<<"\n";}
    for (int i = 0; i<answers_U.size(); i++){std::cout<<answers_U[i]<<"\n";}
    std::cout<<"\nThere is/are "<<(answers_L.size()+answers_U.size())<<" possible value(s) of theta.\n";
    }

//This function is to check whether a value is in a vector
// Returns a value of true if the value is not present
bool check_not_present (double value, std::vector <double> vector, bool check_all, std::vector <int> indexes = {0}){
    if (check_all) {    for ( int i = 0; i<vector.size(); i++)
                            { if (value == vector[i]) {return false;} }
                                                                                                    }
    else if ( !check_all and indexes.size() == 1 and indexes[0] == -1) 
        { if (!vector.empty()) { if (value == vector.back()) {return false;} }                      }
    else { for ( int m = 0; m<indexes.size(); m++)
                { if( value == vector[indexes[m]])
                    {return false;}              }                                                  }
    return true;                                                                                           }
//This is the function for doing the main operation of the program
void decide (){
    std::cout<<"\nInsert the number of the trigonometric function you want:\n";
    std::cout<<"1. Sin()\n";
    std::cout<<"2. Cos()\n";
    std::cout<<"3. Tan()\n";
    std::cin>>operation;
    
    if (operation==1){
        std::cout<<"Insert the value of the constant: ";
        std::cin>>constant;
        if (not(-1<=constant and constant<=1)) {std::cout<<"ERROR ! The constant for sin() has to be inbetween -1 and 1\n"; decide();}
        get_info();
        U = 0;
        L = 1;
        answers_U={};
        answers_L={};

        //Adding the values in the direction of the upper boundary
        result = upper_boundary; //Just to make the condition of the while loop verified so that it can start
        while (result<=upper_boundary){
            result = (asin(constant) *180/M_PI)+ U*360;
            if ( result > upper_boundary ) {break;}
            if ( lower_boundary <= result and result <= upper_boundary) {
                if (not(answers_U.empty())){ if ( result != answers_U.back() ) {answers_U.push_back(result);} }
                                            else {answers_U.push_back(result);} } 
            result =  180 - (asin(constant)* 180/M_PI) + U*360;
            if ( result > upper_boundary ) {break;}
            if (not(answers_U.empty())){
            if ( result == answers_U.back() ) {U++; continue;}}
            if ( lower_boundary <= result and result <= upper_boundary) { answers_U.push_back(result); }
            U++;
        }
        
        //Adding the values in the direction of the lower boundary
        result = lower_boundary; //Just to make the condition of the while loop verified so that it can start
        while ( result >= lower_boundary ){
            result = 180 - (asin(constant) * 180/M_PI)- L*360;
            if (result < lower_boundary) {break;}
            if (not(answers_U.empty())) { if (result != answers_U[0] and result<=upper_boundary) {
                                                if ( not(answers_L.empty()) ){
                                                    if (result != answers_L.back()) {answers_L.push_back(result);} }
                                                else {answers_L.push_back(result);}  
                                                                                                }
                                        }
            else if (answers_U.empty()) {
                if (result <=upper_boundary ) {
                        if ( not(answers_L.empty()) ) {
                                if (result != answers_L.back()) {answers_L.push_back(result);} }
                        else {answers_L.push_back(result);} }
                                        }

            result = (asin(constant) * 180/M_PI) - L*360;
            if ( result < lower_boundary ) {break;}
            if ( result > upper_boundary ) {L++; continue;}
            if (not(answers_L.empty())) {if (result == answers_L.back()) {L++; continue;}}
            if (answers_U.empty()){if(result<=upper_boundary){answers_L.push_back(result);}}
            else if (not(answers_U.empty())) 
            {if (result != answers_U[0] and result != answers_U[1] and result != answers_U[2] and result != answers_U[3]) {answers_L.push_back(result);}}
            L++;
            }
        
        //Printing off the theta values
        print_theta_values();} 

    else if (operation==2){
        std::cout<<"Insert the value of the constant: ";
        std::cin>>constant;
        if (not(-1<=constant and constant<=1)) {std::cout<<"ERROR ! The constant for cos() has to be inbetween -1 and 1\n"; decide();}
        get_info();
        U = 0;
        L = 1;
        answers_U={};
        answers_L={};
        
        //Adding the values in the direction of the upper boundary
        result= upper_boundary;
        while (result<=upper_boundary){
            result = (acos(constant)* 180/M_PI) + U*360;
            if ( lower_boundary <= result and result <= upper_boundary ) {
                if (not(answers_U.empty())) { if (result != answers_U.back()) {answers_U.push_back(result);}} 
                else {answers_U.push_back(result);}}
            result = (360 - (acos(constant) * 180/M_PI)) + U*360;
            if ( lower_boundary <= result and result <= upper_boundary ) {
                if (not(answers_U.empty())) { if (result != answers_U.back()) {answers_U.push_back(result);}} 
                else {answers_U.push_back(result);}}
            U++;
        }

        //Adding the values in the direction of the lower boundary
        result = lower_boundary;
        while (result>=lower_boundary){
            result = (360 - (acos(constant) * 180/M_PI)) - L *360;
            if (result < lower_boundary) {break;}
            if ( check_not_present(result, answers_L, false, {-1}) and result <= upper_boundary and check_not_present(result,answers_U, true))
                 {answers_L.push_back(result);}
            result = (acos(constant) * 180/M_PI) - L * 360;
            if (result < lower_boundary) {break;}
            if (not(answers_L.empty())){
            if ( result != answers_L.back() and result <= upper_boundary ) {answers_L.push_back(result);}}
            else if (answers_L.empty()){if (result<=upper_boundary) {answers_L.push_back(result);}}
            L++;
        }

        print_theta_values();}

    else if (operation==3){
        std::cout<<"Insert the value of the constant: ";
        std::cin>>constant;
        get_info();
        U = 0;
        L = 1;
        answers_U={};
        answers_L={};

        //Adding the values in the direction of the upper boundary
        result= upper_boundary;
        while (result<=upper_boundary){
            result = ((atan(constant)* 180/M_PI) + U * 180);
            if ( lower_boundary <= result and result <= upper_boundary ){answers_U.push_back(result);}
            U++;
        }

        //Adding values in the direction of the lower boundary
        result = lower_boundary;
        while (result>=lower_boundary){
            result = ((atan(constant)* 180/M_PI) - L * 180);
            if (lower_boundary <= result and result<=upper_boundary) {answers_L.push_back(result);}
            L++;
        }

        print_theta_values();}

    else {std::cout<<"INVALID INPUT ! Please enter the number of an existing operation.\n";}
}

int main() {
    std::cout<<"This program was coded by Saifeldin Mohamed Farid from 11XE in 2020\n";
    std::cout<<"-------------------------------------------------------------------\n";
    std::cout<<"TRIGONOMETRIC EQUATIONS CALCULATOR\n";
    std::cout<<"-------------------------------------------------------------------\n\n";
    std::cout<<"HINT: If you want to insert an irrational number or a recurring number:\n      insert it rounded to 6 significant figures.\n";
    while (true){decide();}
}
