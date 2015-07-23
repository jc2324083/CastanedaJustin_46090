/* 
 * File:   main.cpp
 * Author: Justin Castaneda
 * Created on July 8, 2015, 10:45 AM
 * Purpose: Retirement Calculator
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
 
//Function Prototypes

//Execute
int main(int argc, char** argv) {
    //Declare Variables
    float salary=90000;               //Average Salary
    float invRate=0.05f;              //Investment Rate -> see Calif Muni Bonds
    float savReq;                     //Saving required at retirement
    float pDep=0.10f;                 //Of your gross Salary-> Percentage Deposit
    float deposit;                    //Yearly deposit in $'s
    float savings=0;                  //Initial Savings at start of Employment
    float year=0;                     //Start at year 0
    
    //Calculate required savings
    savReq=salary/invRate;
    
    //Loop to calculate when Retirement is possible
    do{
        deposit=pDep*salary;            //Deposit based salary
        savings*=(1+invRate);           //Earning based upon investment rate
        savings+=deposit;               //Add the deposit after earning interest 
        year++;
    }while(savings<savReq);             //When we have enough to retire then exit the loop

    //Display the results
    cout<<"I can retire in "<<year<<" (years) with $"
            <<savings<<" in savings!!!"<<endl;
    
    //Exit
    return 0;
}

