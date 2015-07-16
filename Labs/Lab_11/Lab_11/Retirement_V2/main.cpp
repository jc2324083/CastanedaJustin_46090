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
float retire(float dep,float pdep,float slry,float save,float inv, float yr,float svRe,int dte,float);
void heading();
void table(float dep,float save,float yr,int dte,float intrs,float svRe);

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
    float date=18;
    float intrst;
    //Calculate required savings and interest
   
    
    heading();
    
    retire(deposit,pDep,salary,savings,invRate,year,savReq,date,intrst);    
    
                                  
    //Exit
    return 0;
}


float retire(float dep,float pdep,float slry,float save,float inv, float yr,float svRe,int dte,float intrs){
     //Loop to calculate when Retirement is possible
    
    svRe=slry/inv;
    do{
        dep=pdep*slry;                  //Deposit based salary
        save*=(1+inv);           //Earning based upon investment rate
        save+=dep;               //Add the deposit after earning interest 
        yr++;
        dte++;
        intrs=save*inv;
     table(dep,save,yr,dte,intrs,svRe);
        
    }while(save<svRe);{ //When we have enough to retire then exit the loop
        
                          }         
   
   
    
    return(save,svRe);

}


void heading(){
    cout<<"-Year- -Date-     -Savings-   -Interest-   -Deposit-"<<endl;
}

void table(float dep,float save,float yr,int dte,float intrs,float svRe){
   
 
      cout<<fixed<<showpoint<<setprecision(2);
      cout<<"  "<<setw(2)<<static_cast<unsigned int>(yr)<<"   6/01/"<<dte<<"   $"<<setw(10)<<save<<"   $"<<setw(8)<<intrs<<"   $"<<setw(5)<<dep<<""<<endl;
  
}